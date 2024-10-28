class Solution {
public:
    int bitwiseComplement(int n){
        if(n==0) return 1;
        int ans=0;
        int cnt=0;
        while(n>0){
            ans=(n&1==1) ? (ans+0*pow(2,cnt++)) : (ans+1*pow(2,cnt++));
            n=n>>1;
        }
        return ans;
    }
};