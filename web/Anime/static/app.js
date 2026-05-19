const searchInput = document.getElementById("searchInput");
const posterGrid = document.getElementById("posterGrid");
const visibleCount = document.getElementById("visibleCount");
const emptyState = document.getElementById("emptyState");

if (searchInput && posterGrid && visibleCount && emptyState) {
  const cards = Array.from(posterGrid.querySelectorAll(".poster-card"));

  const updateFilter = () => {
    const keyword = searchInput.value.trim().toLowerCase();
    let visible = 0;

    cards.forEach((card) => {
      const matched = card.dataset.search?.includes(keyword) ?? false;
      card.hidden = !matched;
      if (matched) {
        visible += 1;
      }
    });

    visibleCount.textContent = String(visible);
    emptyState.hidden = visible !== 0;
  };

  searchInput.addEventListener("input", updateFilter);
  updateFilter();

  const prefetched = new Set();
  cards.forEach((card) => {
    const link = card.querySelector("a");
    if (!link) {
      return;
    }

    const prefetch = () => {
      if (prefetched.has(link.href)) {
        return;
      }

      const hint = document.createElement("link");
      hint.rel = "prefetch";
      hint.href = link.href;
      document.head.appendChild(hint);
      prefetched.add(link.href);
    };

    card.addEventListener("mouseenter", prefetch, { once: true });
    card.addEventListener("focusin", prefetch, { once: true });
  });
}

const playbackForm = document.querySelector("[data-playback-form]");

if (playbackForm instanceof HTMLFormElement) {
  const playbackInput = playbackForm.querySelector("[data-playback-input]");
  const editToggle = playbackForm.querySelector("[data-edit-toggle]");
  const saveButton = playbackForm.querySelector("[data-save-button]");

  if (
    playbackInput instanceof HTMLInputElement &&
    editToggle instanceof HTMLButtonElement &&
    saveButton instanceof HTMLButtonElement
  ) {
    let editing = false;

    const syncEditingState = () => {
      playbackForm.dataset.editing = editing ? "true" : "false";
      playbackInput.readOnly = !editing;
      editToggle.setAttribute("aria-pressed", editing ? "true" : "false");
      editToggle.classList.toggle("is-active", editing);
      saveButton.disabled = !editing;

      if (editing) {
        playbackInput.focus();
        playbackInput.setSelectionRange(
          playbackInput.value.length,
          playbackInput.value.length,
        );
      } else {
        playbackInput.blur();
      }
    };

    const openPlaybackUrl = () => {
      const targetUrl = playbackInput.value.trim();
      if (!targetUrl) {
        return;
      }
      window.open(targetUrl, "_blank", "noopener,noreferrer");
    };

    editToggle.addEventListener("click", () => {
      editing = !editing;
      syncEditingState();
    });

    playbackInput.addEventListener("click", (event) => {
      if (editing) {
        return;
      }
      event.preventDefault();
      openPlaybackUrl();
    });

    playbackInput.addEventListener("keydown", (event) => {
      if (editing) {
        return;
      }
      if (event.key === "Enter" || event.key === " ") {
        event.preventDefault();
        openPlaybackUrl();
      }
    });

    playbackForm.addEventListener("submit", () => {
      editing = false;
    });

    syncEditingState();
  }
}

const episodesPanel = document.querySelector("[data-episodes-panel]");

if (episodesPanel instanceof HTMLElement) {
  const configToggle = episodesPanel.querySelector("[data-episodes-config-toggle]");
  const configForm = episodesPanel.querySelector("[data-episodes-config-form]");

  if (
    configToggle instanceof HTMLButtonElement &&
    configForm instanceof HTMLFormElement
  ) {
    const syncConfigState = (open) => {
      configForm.hidden = !open;
      configToggle.setAttribute("aria-expanded", open ? "true" : "false");
      configToggle.classList.toggle("is-active", open);
    };

    syncConfigState(false);
    configToggle.addEventListener("click", () => {
      syncConfigState(configForm.hidden);
    });
  }
}
