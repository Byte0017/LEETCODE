class Solution {
public:
    int count(int dist,int k,vector<int>& nums) {
        int cnt=0;
        for(int i=0;i<nums.size();i++) {
            int target=nums[i]-dist;
            int j=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
            cnt+=i-j;
        }
        return cnt;
    }
    int smallestDistancePair(vector<int>& nums,int k) {
        sort(nums.begin(),nums.end());
        int left=0,right=nums.back()-nums.front();
        while(left<right) {
            int mid=(left+right)>>1;
            if(count(mid,k,nums)>=k)
                right=mid;
            else
                left=mid+1;
        }
        return left;
    }
};
// class Solution {
// public:
//     int smallestDistancePair(vector<int>& nums, int k) {
//         //Approach 1  gives TLE
//         // vector<int>ans;
//         // for(int i=0;i<nums.size()-1;i++){
//         //     for(int j=i+1;j<nums.size();j++){
//         //         int diff=abs(nums[i]-nums[j]);
//         //         ans.push_back(diff);
//         //     }
//         // }
//         // sort(ans.begin(),ans.end());
//         // return ans[k-1];

//         //Approach 2 use max heap
//         // priority_queue<int>pq;
//         // cout<<nums.size()<<endl;
//         // for(int i=0;i<nums.size()-1;i++){
//         //     for(int j=i+1;j<nums.size();j++){
//         //         int diff=abs(nums[i]-nums[j]);
//         //         cout<<diff<<" ";
//         //         if(k>0){
//         //             pq.push(diff);
//         //             k--;
//         //         }
//         //         else{
//         //             //k 0 ho gya then
//         //             if(diff<=pq.top()){
//         //                 pq.pop();
//         //                 pq.push(diff);
//         //             }
//         //         }
//         //     }
//         // }
        
//         // return pq.top();

//         //Approach Binary Search
        
//     }
// };