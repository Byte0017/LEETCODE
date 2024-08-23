// class Solution {
// public:
//     int totalHammingDistance(vector<int>& nums) {
//         int dist=0;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 //use XOR
//                 int temp=nums[i]^nums[j];
//                 while(temp>0){
//                     dist+=(temp&1==1) ? 1:0;
//                     temp=temp>>1;
//                     while(temp>0 && temp&1!=1){
//                         temp=temp>>1;
//                     } 
//                 }
//             }
//         }
//         return dist;
//     }
// };
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        // int ans = 0;
        // for (int i = 0; i < 31; ++i) {
        //     int a = 0, b = 0;
        //     for (int& v : nums) {
        //         int t = (v >> i) & 1;
        //         a += t;
        //         b += t ^ 1;
        //     }
        //     ans += a * b;
        // }
        // return ans;

        //count total no of 1 and 0 present at each bit in arr for all element
        //ans+=cnt*1+cnt*2

        int ans=0;
        for(int i=0;i<30;++i){
            int a=0,b=0; //a is for 1 and b is for 0
            
            for(int j=0;j<nums.size();++j){
                int temp=nums[j];
                temp=temp>>i;
                if(temp&1) a++;
                else b++;
            }
            ans+=a*b;
        }
        return ans;
    }
};