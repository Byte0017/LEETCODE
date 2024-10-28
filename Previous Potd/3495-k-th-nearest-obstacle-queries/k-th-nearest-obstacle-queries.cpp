class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& arr, int k) {
        vector<int>ans;
        priority_queue<int>pq;  //max heap

        for(int i=0;i<arr.size();i++){
            int dist = abs(arr[i][0])+abs(arr[i][1]);
            if(pq.size()<k-1){
                pq.push(dist);
                ans.push_back(-1);
            }
            else if(pq.size()==k-1){
                  pq.push(dist);
                  ans.push_back(pq.top());
            }
            else{
                if(dist<pq.top()){
                    pq.pop();
                    pq.push(dist);
                    ans.push_back(pq.top());
                }
                else ans.push_back(pq.top());
            }     
        }
        return ans;
    }
};