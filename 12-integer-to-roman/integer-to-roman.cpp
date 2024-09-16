class Solution {
public:
    unordered_map<int, string> mp;
    
    // Constructor to initialize the map
    Solution() {
        mp[1] = "I"; mp[2] = "II"; mp[3] = "III"; mp[4] = "IV"; mp[5] = "V"; mp[6] = "VI"; mp[7] = "VII"; mp[8] = "VIII"; mp[9] = "IX";
        mp[10] = "X"; mp[20] = "XX"; mp[30] = "XXX"; mp[40] = "XL"; mp[50] = "L"; mp[60] = "LX"; mp[70] = "LXX"; mp[80] = "LXXX"; mp[90] = "XC";
        mp[100] = "C"; mp[200] = "CC"; mp[300] = "CCC"; mp[400] = "CD"; mp[500] = "D"; mp[600] = "DC"; mp[700] = "DCC"; mp[800] = "DCCC"; mp[900] = "CM";
        mp[1000] = "M"; mp[2000] = "MM"; mp[3000] = "MMM";
    }

    string intToRoman(int num) {
        vector<string> v;
        int place = 1;

        while (num > 0) {
            int x = num % 10;
            num = num / 10;
            x = x * place;
            place = place * 10;
            if (x > 0) {
                v.push_back(mp[x]);
            }
        }
        reverse(v.begin(), v.end());
        string str;
        for (auto x : v) {
            str += x;
        }
        return str;
    }
};
