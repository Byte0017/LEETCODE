class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      multimap<int,int>mp;
      vector<int>ans;
      for(int i=0;i<arr.size();i++){
         int diff=abs(arr[i]-x);
         mp.insert(pair<int, int>(diff,arr[i]));
      }
      for(auto it:mp){
          ans.push_back(it.second);
          if(ans.size()==k) break;
      }
      sort(ans.begin(),ans.end());
      return ans;
    }

    // vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    //   int l=0,h=arr.size()-1;
    //   while(h-l>=k){
    //     if(x-arr[l]>arr[h]-x){
    //       l++;
    //     }
    //     else{
    //       h--;
    //     }
    //   }
    //   vector<int>ans;
    //   for(int i=l;i<=h;i++){
    //     ans.push_back(arr[i]);
    //   }
    //   return ans;
    // }
};