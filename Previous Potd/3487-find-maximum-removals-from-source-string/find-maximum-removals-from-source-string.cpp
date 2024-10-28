
class Solution {
public:
    // Set to hold the indices from targetIndices where characters can be removed
    unordered_set<int> st;
    
    // DP table for memoization
    int dp[3004][3004];

    // Recursive function to calculate the maximum characters removable
    int calc(int idx1, int idx2, string &s, string &p) {
        int n = s.size(), m = p.size();

        // Base case: if we have reached the end of source string
        if (idx1 == n) {
            return (idx2 == m) ? 0 : -1e6; // If pattern not matched, return a large negative value
        }
        
        // Check if the result is already computed
        if (dp[idx1][idx2] != -1) {
            return dp[idx1][idx2];
        }
        
        // Not take
        int ans = calc(idx1 + 1, idx2, s, p);
        
        // Case 2: Remove the current character if it is in targetIndices
        if (st.count(idx1)) {
            ans = std::max(ans, 1 + calc(idx1 + 1, idx2, s, p));
        }
        
        // Case 3: Match the current character of source and pattern
        if (idx2 < m && s[idx1] == p[idx2]) {
            ans = std::max(ans, calc(idx1 + 1, idx2 + 1, s, p));
        }
        
        // Memoize the result for this state
        return dp[idx1][idx2] = ans;
    }

    // Main function to find the maximum number of characters that can be removed
    int maxRemovals(std::string source, std::string pattern, std::vector<int>& targetIndices) {
        // Populate the set with target indices
        for (auto x : targetIndices) {
            st.insert(x);
        }

        // Initialize the DP table with -1

        memset(dp, -1, sizeof(dp));

        // Start the recursive calculation
        return calc(0, 0, source, pattern);
    }
};
