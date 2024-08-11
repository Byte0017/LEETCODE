class Solution {
public:
       string minWindow(string s, string t) {
    vector<int> count(128, 0);
    for (char c : t) {
        count[c]++;
    }

    int required = t.size();
    int minLength = INT_MAX;
    int l = 0, r = 0, start = 0;

    while (r < s.size()) {
        if (count[s[r]] > 0) {
            required--;
        }
        count[s[r]]--;
        r++;

        while (required == 0) {
            if (r - l < minLength) {
                minLength = r - l;
                start = l;
            }
            count[s[l]]++;
            if (count[s[l]] > 0) {
                required++;
            }
            l++;
        }
    }

    return minLength == INT_MAX ? "" : s.substr(start, minLength);
}
};