class Solution {
public:
    int findComplement(int n) {
        int ans=0;
        int cnt=0;
        while(n>0){
            if(n&1){
                ans+=0*pow(2,cnt++);
            }
            else{
                ans+=1*pow(2,cnt++);
            }
            //right shift
            n=n>>1;
        }
        return ans;
    }
};