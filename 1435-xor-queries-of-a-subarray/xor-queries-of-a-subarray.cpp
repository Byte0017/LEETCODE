class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto v:queries){
            int i=v[0];
            int j=v[1];
            if(i==j){
                ans.push_back(arr[i]);
                continue;
            } 

            int x=arr[i];
            for(i=i+1;i<=j;i++){
                x=x^arr[i];
            }
            ans.push_back(x);
        }
        return ans;
    }
};