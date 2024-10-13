class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();  

        //minHeap that stores element,listNo,minEl_index
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;

        int maxEl=INT_MIN;
        for(int i=0;i<k;i++){
            pq.push({nums[i][0],i,0}); //{element,listIndex,index}
            maxEl=max(maxEl,nums[i][0]);
        }

        //rangeVector
        vector<int>range = {-1000000, 1000000};


        while(!pq.empty()){
            vector<int>curr=pq.top();
            pq.pop();

            int minEl = curr[0];
            int list_idx = curr[1];
            int minEl_idx= curr[2];

            //update range
            if(maxEl-minEl < range[1]-range[0]){
                range[0] = minEl;
                range[1] = maxEl;
            }

            //check khi out of bount to nhi ho gya
            if(minEl_idx+1 < nums[list_idx].size()) {
                pq.push({nums[list_idx][minEl_idx+1], list_idx, minEl_idx+1});
                maxEl = max(maxEl, nums[list_idx][minEl_idx+1]);
            } else {
                break;
            }
        }
        return range;
    }
};



