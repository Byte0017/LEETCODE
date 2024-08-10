class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(),nums.end());
        // return nums[nums.size()-k];
        // priority_queue<int>pq;
        // for(int i=0;i<nums.size();i++){
        //     pq.push(nums[i]);
        // } 
        // while(k>1){
        //     pq.pop();
        //     k--;
        // } 
        // return pq.top();

        //using min heap
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<k;i++) pq.push(nums[i]);
        for(int i=k;i<nums.size();i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
};