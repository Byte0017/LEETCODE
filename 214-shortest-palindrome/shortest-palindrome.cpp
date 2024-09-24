class Solution {
public:
    
void LPS(const string& s, vector<int>& lps) {
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

string shortestPalindrome(string s) {
    if (s.empty()) return s;

    string rev = s;
    reverse(rev.begin(), rev.end());
    string temp=rev;
    rev = s + "#" + rev;

    vector<int> lps(rev.length(), 0);
    LPS(rev, lps);

    int len= lps.back();

    // Add the non-palindromic suffix of original string reversed at the front
    string str=temp.substr(0,temp.size()-len);

    return str + s;
}

};