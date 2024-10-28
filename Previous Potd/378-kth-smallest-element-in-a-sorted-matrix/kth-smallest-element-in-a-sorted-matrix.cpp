class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        //using max heap
        priority_queue<int>pq;
        //insert first k element
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(k){
                    pq.push(matrix[i][j]);
                    k--;
                }
                else if(pq.top()>matrix[i][j]){
                    pq.pop();
                    pq.push(matrix[i][j]);
                }
            }
        }
        return pq.top();
    }
};