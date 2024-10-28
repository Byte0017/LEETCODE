class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
        int total=0;

        int maxH=arr[0];
        int index=0;
        for(int i=0;i<n;i++){
            if(maxH<arr[i]){
                maxH=arr[i];
                index=i;
            }
        } 
        //traverse i=0 to i==index-1
        int lMax=0;
        for(int i=0;i<index;i++){
            int x=min(lMax,maxH);
            total+=(x>arr[i])? x-arr[i]: 0;
            //update lMax
            lMax=max(lMax,arr[i]);
        }

        //traverse i=n-1 to i>index
        int rMax=0;
        for(int i=n-1;i>index;i--){
            int x=min(rMax,maxH);
            total+=(x>arr[i])? x-arr[i]: 0;
            //update lMax
            rMax=max(rMax,arr[i]);
        }
        return total;
    }
};