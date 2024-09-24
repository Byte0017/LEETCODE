class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> mp;
        for (auto& it : arr1) {
            string s = to_string(it);
            string prefix = "";
            for (auto ch : s) {
                prefix += ch;
                mp[prefix]++;
            }
        }
        int ans = 0;
        for (auto it : arr2) {
            string s = to_string(it);
            string prefix = "";
            for (auto ch : s) {
                prefix += ch;
                if (mp.find(prefix) != mp.end()) {
                    int sz = prefix.size();
                    ans = max(ans, sz);
                }
            }
        }

        return ans;
    }
};