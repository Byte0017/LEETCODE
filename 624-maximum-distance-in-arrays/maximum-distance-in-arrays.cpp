class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        pair<int,int>min1=make_pair(INT_MAX,-1);
        pair<int,int>min2=make_pair(INT_MAX,-1);
        pair<int,int>max1=make_pair(INT_MIN,-1);
        pair<int,int>max2=make_pair(INT_MIN,-1);
        
        min1.first=arr[0][0] , max1.first=arr[0][arr[0].size()-1];
        min1.second=0 , max1.second=0;
        
        for(int i=1;i<arr.size();i++){
            int mini=arr[i][0];
            int maxi=arr[i][arr[i].size()-1];

            //store min1 min2 
            if(mini<min1.first){
               //update min1 and min2
               min2.first=min1.first;
               min2.second=min1.second;

               min1.first=mini;
               min1.second=i;
            }
            else if(mini<min2.first){
                //only update min2
                min2.first=mini;
                min2.second=i;
            }

            //Update max1 && max2
            if(maxi>max1.first){
               //update max1 and max2
               max2.first=max1.first;
               max2.second=max1.second;

               max1.first=maxi;
               max1.second=i;
            }
            else if(maxi>max2.first){
                //only update max2
                max2.first=maxi;
                max2.second=i;
            }
        }

        if(max1.second==min1.second){
            if(max2.second==min2.second){
                return max(abs(max1.first-min2.first),abs(max2.first-min1.first));
            }
            else{
                int temp= max(abs(max2.first-min2.first),abs(max2.first-min1.first));
                return max(abs(max1.first-min2.first),temp);
            }
        }
        else{
            return abs(max1.first-min1.first);
        }
        return -1;
    }
};