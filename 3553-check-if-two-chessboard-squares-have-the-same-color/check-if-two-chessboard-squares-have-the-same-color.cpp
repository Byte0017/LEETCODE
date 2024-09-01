class Solution {
public:
    bool checkTwoChessboards(string s1, string s2) {
        int clr1=s1[0]+s1[1]-'0';
        int clr2=s2[0]+s2[1]-'0';   

        if(clr1%2 == clr2%2) return true;

        return 0;
    }
};