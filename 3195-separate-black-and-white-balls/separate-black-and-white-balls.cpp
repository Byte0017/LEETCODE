class Solution {
public:
#define ll long long
    long long minimumSteps(string s) {
        ll cnt=0;
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]=='1' && s[j]=='0'){
                cnt+=j-i;
                swap(s[i],s[j]);
                i++,j--;
            }
            else if(s[i]=='0') i++;
            else if(s[j]=='1') j--; 
        }

        return cnt;
    }
};