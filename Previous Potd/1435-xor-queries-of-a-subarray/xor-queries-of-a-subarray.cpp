class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // vector<int>ans;
        // for(auto v:queries){
        //     int i=v[0];
        //     int j=v[1];
        //     if(i==j){
        //         ans.push_back(arr[i]);
        //         continue;
        //     } 

        //     int x=arr[i];
        //     for(i=i+1;i<=j;i++){
        //         x=x^arr[i];
        //     }
        //     ans.push_back(x);
        // }
        // return ans;

        vector<int>ans;
        //cumulative XOR
        for(int i=1;i<arr.size();i++){
            arr[i]=arr[i]^arr[i-1];
        }

        for(auto v:queries){
            int i=v[0];
            int j=v[1];
            int val=arr[j]^(i==0?0:arr[i-1]);
            ans.push_back(val);
        }
        return ans;
    }
};