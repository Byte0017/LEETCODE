class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();  
        vector<int>arrIdx(k,0);//this stroe the index of every row vector in nums
        vector<int>range={-100000 , 100000};//store min and max

        while(true){
            int minEl=INT_MAX;
            int maxEl=INT_MIN;
            int idx_minEl=0;

            for(int i=0;i<k;i++){  // i tells which list is taken
                int x=nums[i][arrIdx[i]];
                if(x<minEl){//update minEl and index ki what is idx for minEl
                    minEl=x;
                    idx_minEl=i;
                }
                maxEl=max(maxEl,nums[i][arrIdx[i]]);
            }
            //update range
            if(range[1]-range[0]>maxEl-minEl){
                range[0]=minEl;
                range[1]=maxEl;
            }

            //to minimize range update minimum idx in arrIdx
            arrIdx[idx_minEl]++;
            if(arrIdx[idx_minEl] >= nums[idx_minEl].size()){
                //if idx is out of bound of any list
                break;
            }
        }
        return range;
    }
};

