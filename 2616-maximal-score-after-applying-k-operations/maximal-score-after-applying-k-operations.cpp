class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long int score=0;
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++) pq.push(nums[i]);
        while(k--){
            score+=pq.top();
            int r=pq.top()%3;
            int x=0;
            if(r>0){
                x=pq.top()/3 +1;
            }
            else x=pq.top()/3;

            pq.pop();
            pq.push(x);
        }
        return score;
    }
};