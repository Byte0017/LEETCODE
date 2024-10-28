class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        for(int i=0;i<31;++i){
            int a=0,b=0;
            int temp1=x;
            int temp2=y;
            temp1=temp1>>i;
            temp2=temp2>>i;
            if(temp1&1) a++;
            else b++;
            if(temp2&1) a++;
            else b++;

            ans+=a*b;
        }
        return ans;
    }
};