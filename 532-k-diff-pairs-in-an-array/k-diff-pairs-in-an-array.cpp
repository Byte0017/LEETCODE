class Solution {
public:
    // Binary Search Method
    bool BS(vector<int>&arr,int s,int x){
      int e=arr.size()-1;
      while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==x){
            return true;
        }
        else if(x>arr[mid]){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
      }
      return false;
    }
    int findPairs(vector<int>& arr, int k){
        int n=arr.size();
        set<pair<int,int>>ans;
        sort(arr.begin(),arr.end());
        //Binary search if a[i] then a[i]+k==a[j] is present or not
        for(int i=0;i<n;i++){
          if(BS(arr,i+1,arr[i]+k)){
             ans.insert({arr[i],arr[i]+k});
          }
        }
        return ans.size();
    }


    
    // int findPairs(vector<int>& nums, int k) {
    //  sort(nums.begin(),nums.end());
    //  set<pair<int,int>>ans;
    //  int i=0,j=1;
    //  while(j<nums.size()){
    //    int diff=nums[j]-nums[i];
    //    if(diff==k){
    //      ans.insert({nums[i],nums[j]});
    //      i++,j++;
    //    }
    //    else{
    //      if(diff>k) i++;
    //      else j++;
    //      if(i==j) j++;
    //    }
    //  }
    //  return ans.size();
    // }
};