class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(int i=0;i<piles.size();i++) pq.push(piles[i]);
        while(k--){
            int x=pq.top();
            pq.pop();
            if(x&1){
                x=x/2+1;
            }
            else x=x/2;
            pq.push(x);
        }
        int total=0;
        while(!pq.empty()) {
            total+=pq.top();
            pq.pop();
        }
        return total;
    }
};