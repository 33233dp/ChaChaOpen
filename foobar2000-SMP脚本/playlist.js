// playlist.js
// Requirements:
// 1. Background: Now Playing cover (with opacity).
// 2. Scrolling.
// 3. Rating: Heart icon (Red=5, Grey<5). Click to toggle.
// 4. Context Menu: Background opacity, Enable/Disable background.
// 5. Auto-scroll: 5s idle -> scroll to playing track.

// ============================================================================
//                                 PROPERTIES
// ============================================================================
var p = {
    bg_opacity: window.GetProperty("Background Opacity", 100), // 0-255
    show_bg: window.GetProperty("Show Background", true),
    font_name: window.GetProperty("Font Name", "Segoe UI"),
    font_size: window.GetProperty("Font Size", 12),
    row_h: window.GetProperty("Row Height", 35),
    header_h: window.GetProperty("Header Height", 30),
    color_highlight: window.GetProperty("Color Highlight", "255,140,0"), // Orange
    color_text: window.GetProperty("Color Text", "220,220,220"),
    color_bg: window.GetProperty("Color Background", "20,20,20")
};

// ============================================================================
//                                   GLOBALS
// ============================================================================
var g_img = null;
var g_font = gdi.Font(p.font_name, p.font_size);
var g_font_heart = gdi.Font("Segoe UI Symbol", p.font_size + 4); // Larger heart
var g_scroll = 0; // Current scroll index (row)
var g_last_action = Date.now();
var g_timer = null;
var ww = 0, wh = 0;
var g_drag_scroll = false;
var g_playlist_items = null; // Cache for playlist items

// Columns Configuration
var g_columns = [
    { label: "Artist", w: 150, tf: "%artist%", sort_tf: "%artist%", sort_desc: false },
    { label: "Title", w: 0, tf: "%title%", sort_tf: "%title%", sort_desc: false }, // w=0 means flexible
    { label: "Album", w: 150, tf: "%album%", sort_tf: "%album%", sort_desc: false },
    { label: "Genre", w: 80, tf: "%genre%", sort_tf: "%genre%", sort_desc: false },
    { label: "Duration", w: 60, tf: "%length%", sort_tf: "%length_seconds%", sort_desc: false },
    { label: "♥", w: 40, tf: null, sort_tf: "%rating%", sort_desc: true }
];

// Colors
function RGB(r, g, b) { return (0xff000000 | (r << 16) | (g << 8) | (b)); }
function RGBA(r, g, b, a) { return ((a << 24) | (r << 16) | (g << 8) | (b)); }

var c_highlight = eval("RGB(" + p.color_highlight + ")");
var c_text = eval("RGB(" + p.color_text + ")");
var c_bg = eval("RGB(" + p.color_bg + ")");
var c_heart_red = RGB(255, 50, 50);
var c_heart_grey = RGB(100, 100, 100);

// ============================================================================
//                                 INITIALIZATION
// ============================================================================
function on_init() {
    update_background();
    update_playlist_items();
    g_timer = window.SetInterval(check_auto_scroll, 1000);
}

// ============================================================================
//                               BACKGROUND LOGIC
// ============================================================================
function update_background() {
    if (!p.show_bg) {
        g_img = null;
        window.Repaint();
        return;
    }
    var handle = fb.GetNowPlaying();
    if (handle) {
        // Load cover art async
        utils.GetAlbumArtAsync(window.ID, handle, 0); 
    } else {
        g_img = null;
        window.Repaint();
    }
}

function on_get_album_art_done(metadb, art_id, image, image_path) {
    g_img = image;
    window.Repaint();
}

function on_playback_new_track(metadb) {
    update_background();
    // Scroll to new track if auto-scroll is "active" logic-wise, 
    // but the requirement says "5s idle -> scroll". 
    // Usually on new track we might want to scroll too, but let's stick to the timer.
    g_last_action = Date.now(); // Reset timer on track change so we don't jump immediately
    window.Repaint();
}

function on_playback_stop(reason) {
    if (reason != 2) { // 2 = starting_another
        g_img = null;
        window.Repaint();
    }
}

// ============================================================================
//                                 PLAYLIST DATA
// ============================================================================
function update_playlist_items() {
    var pl = plman.ActivePlaylist;
    g_playlist_items = plman.GetPlaylistItems(pl);
}

function on_playlist_items_added(playlistIndex) {
    if (playlistIndex == plman.ActivePlaylist) {
        update_playlist_items();
        window.Repaint();
    }
}

function on_playlist_items_removed(playlistIndex, newCount) {
    if (playlistIndex == plman.ActivePlaylist) {
        update_playlist_items();
        window.Repaint();
    }
}

function on_playlist_items_reordered(playlistIndex) {
    if (playlistIndex == plman.ActivePlaylist) {
        update_playlist_items();
        window.Repaint();
    }
}

function on_playlist_switch() {
    update_playlist_items();
    g_scroll = 0; // Reset scroll on playlist switch? Or keep?
    window.Repaint();
}

// ============================================================================
//                                 AUTO SCROLL
// ============================================================================
function check_auto_scroll() {
    var now = Date.now();
    if (now - g_last_action > 5000) {
        scrollToNowPlaying();
    }
}

function scrollToNowPlaying() {
    var handle = fb.GetNowPlaying();
    if (!handle) return;
    
    var pl = plman.ActivePlaylist;
    var idx = plman.GetPlayingItemLocation().PlaylistItemIndex;
    
    // Only scroll if playing item is in active playlist
    if (plman.GetPlayingItemLocation().PlaylistIndex != pl) return;
    if (idx == -1) return;

    // Target: Show at 2nd or 3rd position (index 1 or 2)
    // So we want g_scroll to be idx - 2
    var target = idx - 2;
    if (target < 0) target = 0;
    
    // Check bounds
    var total = g_playlist_items ? g_playlist_items.Count : 0;
    var visible_rows = Math.ceil((wh - p.header_h) / p.row_h);
    if (target > total - visible_rows) target = total - visible_rows;
    if (target < 0) target = 0;

    if (g_scroll != target) {
        g_scroll = target;
        window.Repaint();
    }
}

// ============================================================================
//                                   PAINTING
// ============================================================================
function on_paint(gr) {
    // Draw Background
    gr.FillSolidRect(0, 0, ww, wh, c_bg);
    
    if (g_img && p.show_bg) {
        var img_w = g_img.Width;
        var img_h = g_img.Height;
        // Scale to fill (UniformToFill)
        var scale_w = ww / img_w;
        var scale_h = wh / img_h;
        var scale = Math.max(scale_w, scale_h);
        var dest_w = img_w * scale;
        var dest_h = img_h * scale;
        var dest_x = (ww - dest_w) / 2;
        var dest_y = (wh - dest_h) / 2;
        
        gr.DrawImage(g_img, dest_x, dest_y, dest_w, dest_h, 0, 0, img_w, img_h, 0, p.bg_opacity);
        
        // Gradient Mask: Center (Transparent) to Bottom (Opaque Background Color)
        // Effectively fading the image out towards the bottom
        // From y=wh/2 to y=wh
        
        // FillGradRect(x, y, w, h, angle, color1, color2, focus)
        // angle: 90 (top to bottom)
        // color1: Transparent (0x00xxxxxx) -> Top
        // color2: Background Color (c_bg) -> Bottom
        
        // Note: c_bg is an integer color (0xFFxxxxxx). We need to make sure alpha is correct.
        // We want to fade TO the background color. So we draw a gradient of the background color
        // starting from alpha 0 to alpha 255.
        
        var c_bg_transparent = c_bg & 0x00FFFFFF; // Set alpha to 0
        var c_bg_opaque = c_bg | 0xFF000000;      // Set alpha to 255
        
        // Gradient Mask:
        // We want the bottom 1/3 to be fully opaque (solid background color).
        // So the gradient should run from top (0) to 2/3 down (wh * 0.66).
        
        var grad_h = wh * 0.92;
        
        // 1. Draw gradient from top to 2/3 height
        gr.FillGradRect(0, 0, ww, grad_h, 90, c_bg_transparent, c_bg_opaque, 1.0);
        
        // 2. Fill the remaining bottom 1/3 with solid opaque background color
        gr.FillSolidRect(0, grad_h, ww, wh - grad_h, c_bg_opaque);
    }

    // --- Calculate Column Widths (Dynamic Title) ---
    var fixed_w = 0;
    var pad = 10;
    for (var i = 0; i < g_columns.length; i++) {
        if (g_columns[i].label != "Title") fixed_w += g_columns[i].w;
    }
    // Update Title width
    for (var i = 0; i < g_columns.length; i++) {
        if (g_columns[i].label == "Title") {
             // Total width - fixed widths - padding for each column (approx)
             g_columns[i].w = Math.max(100, ww - fixed_w - (g_columns.length * pad)); 
        }
    }

    // --- Draw Header ---
    gr.FillSolidRect(0, 0, ww, p.header_h, RGBA(0, 0, 0, 150)); // Darker background for header
    gr.DrawLine(0, p.header_h, ww, p.header_h, 1.0, RGBA(255, 255, 255, 50)); // Separator
    
    var cx = 0;
    for (var i = 0; i < g_columns.length; i++) {
        var col = g_columns[i];
        // Draw Header Text
        // Flags: 0x00000000 (Left) | 0x10000000 (VCenter) | 0x00000004 (NoWrap) | 0x00001000 (NoClip - optional)
        // Explicitly using 0 for Horizontal Alignment (Left)
        gr.DrawString(col.label, g_font, c_text, cx + pad, 0, col.w, p.header_h, 0x10000000); 
        
        // Draw sort indicator if needed (optional)
        if (col.sort_desc) {
            gr.DrawString("↓", g_font, c_text, cx + col.w - 15, 0, 15, p.header_h, 0x00000000 | 0x10000000);
        } else {
             // gr.DrawString("↑", g_font, c_text, cx + col.w - 15, 0, 15, p.header_h, 0x00000000 | 0x10000000);
        }
        
        cx += col.w + pad;
    }

    // --- Draw Playlist ---
    var pl = plman.ActivePlaylist;
    
    // Safety check
    if (!g_playlist_items || g_playlist_items.Count == 0) {
        // Try update if null
        if (!g_playlist_items) update_playlist_items();
        
        if (!g_playlist_items || g_playlist_items.Count == 0) {
            gr.DrawString("Playlist is empty", g_font, c_text, 0, p.header_h, ww, wh - p.header_h, 0x11111000); // Center
            return;
        }
    }
    
    var total = g_playlist_items.Count;
    
    // Render info
    var visible_rows = Math.ceil((wh - p.header_h) / p.row_h);
    var start_idx = Math.floor(g_scroll);
    var end_idx = start_idx + visible_rows;
    if (end_idx > total) end_idx = total;

    var y = p.header_h; // Start below header
    
    // Get handles for visible range
    var playing_loc = plman.GetPlayingItemLocation();
    var playing_idx = (playing_loc.PlaylistIndex == pl) ? playing_loc.PlaylistItemIndex : -1;

    for (var i = start_idx; i < end_idx; i++) {
        var item = g_playlist_items[i]; 
        if (!item) continue;

        // Playing highlight
        if (i == playing_idx) {
            gr.FillSolidRect(0, y, ww, p.row_h, RGBA(255, 255, 255, 20)); // Subtle highlight
            gr.DrawRect(0, y, ww - 1, p.row_h - 1, 1.0, c_highlight); // Border
        }

        // Text Colors
        var color = c_text;
        if (i == playing_idx) color = c_highlight;

        // Draw Columns
        var cx = 0;
        for (var c = 0; c < g_columns.length; c++) {
            var col = g_columns[c];
            
            if (col.label == "♥") {
                 // Draw Rating (Heart)
                 var rating = fb.TitleFormat("%rating%").EvalWithMetadb(item);
                 var is_heart_red = (rating == "5");
                 var heart_color = is_heart_red ? c_heart_red : c_heart_grey;
                 var heart_char = "\u2665"; // Black Heart Suit
                 
                 // Left align
                 gr.DrawString(heart_char, g_font_heart, heart_color, cx + pad, y, col.w, p.row_h, 0x10000000); 
            } else {
                 // Regular Text
                 var text = fb.TitleFormat(col.tf).EvalWithMetadb(item);
                 gr.DrawString(text, g_font, color, cx + pad, y, col.w, p.row_h, 0x10000000); // VCenter, Left Align
            }
            
            cx += col.w + pad;
        }

        y += p.row_h;
    }
    
    // Scrollbar (Simple)
    if (total > visible_rows) {
        var sb_x = ww - 5;
        var sb_w = 5;
        var sb_h = (visible_rows / total) * (wh - p.header_h);
        if (sb_h < 20) sb_h = 20;
        var sb_y = p.header_h + (g_scroll / total) * (wh - p.header_h);
        if (sb_y + sb_h > wh) sb_y = wh - sb_h;
        
        gr.FillSolidRect(sb_x, sb_y, sb_w, sb_h, RGBA(255, 255, 255, 100));
    }
}

// ============================================================================
//                                 INTERACTION
// ============================================================================
function on_size() {
    ww = window.Width;
    wh = window.Height;
}

function on_mouse_wheel(step) {
    update_interaction();
    // Safety check
    if (!g_playlist_items) update_playlist_items();
    if (!g_playlist_items) return;
    
    var total = g_playlist_items.Count;
    var visible_rows = Math.ceil((wh - p.header_h) / p.row_h);
    
    if (total > visible_rows) {
        g_scroll -= step * 3; // Speed
        if (g_scroll < 0) g_scroll = 0;
        if (g_scroll > total - visible_rows) g_scroll = total - visible_rows;
        window.Repaint();
    }
}

function on_mouse_lbtn_up(x, y) {
    update_interaction();
    var pl = plman.ActivePlaylist;
    
    // --- Header Click (Sorting) ---
    if (y < p.header_h) {
        var cx = 0;
        var pad = 10;
        
        // Need to calculate column widths again to be accurate
        var fixed_w = 0;
        for (var i = 0; i < g_columns.length; i++) {
            if (g_columns[i].label != "Title") fixed_w += g_columns[i].w;
        }
        var title_w = Math.max(100, ww - fixed_w - (g_columns.length * pad)); 

        for (var i = 0; i < g_columns.length; i++) {
            var col = g_columns[i];
            var col_w = (col.label == "Title") ? title_w : col.w
            
            if (x >= cx && x < cx + col_w + pad) {
                // Clicked Header i
                col.sort_desc = !col.sort_desc; // Toggle direction
                
                // Sort
                // plman.SortByFormat(playlistIndex, pattern, direction)
                // direction: > 0 descending, 0 ascending? 
                // Based on standard usage: 0 is ascending, 1 is descending.
                
                var dir = col.sort_desc ? 1 : 0; 
                plman.SortByFormat(pl, col.sort_tf, dir);
                
                window.Repaint();
                return;
            }
            cx += col_w + pad;
        }
        return;
    }

    // --- Item Click ---
    // Safety check
    if (!g_playlist_items) update_playlist_items();
    if (!g_playlist_items) return;
    
    var total = g_playlist_items.Count;
    
    var clicked_row_idx = Math.floor((y - p.header_h) / p.row_h); // Adjust for header
    var abs_idx = Math.floor(g_scroll) + clicked_row_idx;
    
    if (abs_idx >= 0 && abs_idx < total) {
        // Clicked Item -> Select Only (Single Click)
        plman.ClearPlaylistSelection(pl);
        plman.SetPlaylistSelectionSingle(pl, abs_idx, true);
        plman.SetPlaylistFocusItem(pl, abs_idx);
    }
}

function on_mouse_lbtn_dblclk(x, y) {
    update_interaction();
    
    if (y < p.header_h) return; // Ignore header double click

    var pl = plman.ActivePlaylist;
    if (!g_playlist_items) update_playlist_items();
    
    var total = g_playlist_items ? g_playlist_items.Count : 0;
    var clicked_row_idx = Math.floor((y - p.header_h) / p.row_h); // Adjust for header
    var abs_idx = Math.floor(g_scroll) + clicked_row_idx;

    if (abs_idx >= 0 && abs_idx < total) {
         plman.ExecutePlaylistDefaultAction(pl, abs_idx);
    }
}

function on_metadb_changed(handle_list, from_should_change_playback_state) {
    // Refresh UI when tags (like RATING) change
    window.Repaint();
}

function on_mouse_rbtn_up(x, y) {
    update_interaction();
    var menu = window.CreatePopupMenu();
    
    menu.AppendMenuItem(0, 1, "Enable Background");
    menu.CheckMenuItem(1, p.show_bg);
    
    var opacity_menu = window.CreatePopupMenu();
    opacity_menu.AppendMenuItem(0, 10, "20%");
    opacity_menu.AppendMenuItem(0, 11, "40%");
    opacity_menu.AppendMenuItem(0, 12, "60%");
    opacity_menu.AppendMenuItem(0, 13, "80%");
    opacity_menu.AppendMenuItem(0, 14, "100%");
    
    // Check current opacity
    if (p.bg_opacity == 51) opacity_menu.CheckMenuItem(10, true);
    if (p.bg_opacity == 102) opacity_menu.CheckMenuItem(11, true);
    if (p.bg_opacity == 153) opacity_menu.CheckMenuItem(12, true);
    if (p.bg_opacity == 204) opacity_menu.CheckMenuItem(13, true);
    if (p.bg_opacity == 255) opacity_menu.CheckMenuItem(14, true);

    opacity_menu.AppendTo(menu, 0x10, "Background Opacity");
    
    // New Menu Items
    menu.AppendMenuItem(0x800, 0, ""); // Separator
    menu.AppendMenuItem(0, 20, "Reload Script");
    menu.AppendMenuItem(0, 21, "Random Sort");

    var idx = menu.TrackPopupMenu(x, y);
    
    if (idx == 1) {
        p.show_bg = !p.show_bg;
        window.SetProperty("Show Background", p.show_bg);
        update_background();
    } else if (idx >= 10 && idx <= 14) {
        var op_map = {10: 51, 11: 102, 12: 153, 13: 204, 14: 255};
        p.bg_opacity = op_map[idx];
        window.SetProperty("Background Opacity", p.bg_opacity);
        window.Repaint();
    } else if (idx == 20) {
        window.Reload();
    } else if (idx == 21) {
        var pl = plman.ActivePlaylist;
        // Random Sort: Usually sorting by $rand() or standard random command
        // Standard random sort title formatting pattern: "$rand()" or similar
        // Or if standard command is preferred: plman.SortByFormat(pl, "", 0) might not be random.
        // Let's use standard title formatting random.
        plman.SortByFormat(pl, "$rand()", 0);
    }
    
    // menu.Dispose(); // Not needed in SMP
    // if (opacity_menu) opacity_menu.Dispose();
    return true;
}

function update_interaction() {
    g_last_action = Date.now();
}

function on_mouse_move(x, y) {
    // Only update interaction if moving significantly? 
    // Usually simple move counts.
    g_last_action = Date.now();
}

// Initialize
on_init();
