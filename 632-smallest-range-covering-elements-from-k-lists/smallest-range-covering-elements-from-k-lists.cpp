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

            //
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


// class Solution {
// public:
//     vector<int> smallestRange(vector<vector<int>>& nums) {
//         int k=nums.size();  
//         vector<int>arrIdx(k,0);//this stroe the index of every row vector in nums
//         vector<int>range={-100000 , 100000};//store min and max

//         while(true){
//             int minEl=INT_MAX;
//             int maxEl=INT_MIN;
//             int idx_minEl=0;

//             for(int i=0;i<k;i++){  // i tells which list is taken
//                 int x=nums[i][arrIdx[i]];
//                 if(x<minEl){//update minEl and index ki what is idx for minEl
//                     minEl=x;
//                     idx_minEl=i;
//                 }
//                 maxEl=max(maxEl,nums[i][arrIdx[i]]);
//             }
//             //update range
//             if(range[1]-range[0]>maxEl-minEl){
//                 range[0]=minEl;
//                 range[1]=maxEl;
//             }

//             //to minimize range update minimum idx in arrIdx
//             arrIdx[idx_minEl]++;
//             if(arrIdx[idx_minEl] >= nums[idx_minEl].size()){
//                 //if idx is out of bound of any list
//                 break;
//             }
//         }
//         return range;
//     }
// };

