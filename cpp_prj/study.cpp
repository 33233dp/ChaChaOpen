class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        char map[256] = "";
        int right = 0, left = 0;
        int result = 0;
        for(right = 0; right < s.size(); right++) {
          map[s[right]]++;
          while(map[s[right]] > 1) {
            map[s[left]]--;
            left++;
          }
          result = max(result, right - left + 1);
        }
        return result;
    }
};