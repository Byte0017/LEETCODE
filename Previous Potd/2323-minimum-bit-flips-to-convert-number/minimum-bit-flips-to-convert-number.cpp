class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt=0;
        while(start>0 || goal>0){
            int mask_S=start&1;
            int mask_G=goal&1;
            if(mask_S != mask_G) cnt++;
            start=start>>1;
            goal=goal>>1;
        }  
        return cnt;
    }
};