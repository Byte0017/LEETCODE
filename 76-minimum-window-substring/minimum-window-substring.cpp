class Solution {
public:

  string minWindow(string s, string t) {
      if (s.empty() || t.empty()) return "";
      // Hash map to store the count of characters in t
      unordered_map<char, int> dict_t;
      for (char c : t) {
          dict_t[c]++;
      }
      // Number of unique characters in t that must be present in the window
      int required = dict_t.size();
      // Left and right pointers for the sliding window
      int l = 0, r = 0;
      // Formed counts how many characters meet the required frequency
      int formed = 0;
      // Hash map to store the counts of characters in the current window
      unordered_map<char, int> window_counts;
      // Result tuple to store the minimum window length, and left, right pointers
      int min_len = INT_MAX;
      int min_left = 0, min_right = 0;
      while (r < s.size()) {
          char c = s[r];
          window_counts[c]++;
          // If the current character's count in the window matches its count in t, increment `formed`
          if (dict_t.find(c) != dict_t.end() && window_counts[c] == dict_t[c]) {
              formed++;
          }
          // Try and contract the window till the point where it ceases to be 'desirable'
          while (l <= r && formed == required) {
              c = s[l];
              // Save the smallest window until now
              if (r - l + 1 < min_len) {
                  min_len = r - l + 1;
                  min_left = l;
                  min_right = r;
              }
              // The character at the position pointed by the `left` pointer is no longer a part of the window
              window_counts[c]--;
              if (dict_t.find(c) != dict_t.end() && window_counts[c] < dict_t[c]) {
                  formed--;
              }
              // Move the left pointer ahead, this would help to look for a new window
              l++;
          }
          // Keep expanding the window by moving the right pointer
          r++;
      }
      return min_len == INT_MAX ? "" : s.substr(min_left, min_len);
   }


};