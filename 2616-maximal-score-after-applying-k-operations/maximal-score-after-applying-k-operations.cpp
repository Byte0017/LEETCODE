class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long int score=0;
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++) pq.push(nums[i]);
        while(k--){
            score+=pq.top();
            int x=pq.top();
            x=ceil(x/3.0);
         
            pq.pop();
            pq.push(x);
        }
        return score;
    }
};