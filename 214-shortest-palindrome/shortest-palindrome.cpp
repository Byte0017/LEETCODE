class Solution {
public:
    
// Function to calculate LPS array (used in KMP)
void calculateLPSArray(const string& s, vector<int>& lps) {
    int length = 0;
    int i = 1;
    lps[0] = 0;
    
    while (i < s.length()) {
        if (s[i] == s[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to find the shortest palindrome using KMP algorithm
string shortestPalindrome(string s) {
    if (s.empty()) return s;

    // Create new string: original + "#" + reverse(original)
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    string s_new = s + "#" + rev_s;

    // Create LPS array for the new string
    vector<int> lps(s_new.length(), 0);
    calculateLPSArray(s_new, lps);

    // Length of the longest palindrome prefix
    int longest_palindrome_prefix_len = lps.back();

    // Add the non-palindromic suffix of original string reversed at the front
    string suffix = s.substr(longest_palindrome_prefix_len);
    reverse(suffix.begin(), suffix.end());

    return suffix + s;
}

};