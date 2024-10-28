class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& arr, int m, int n) {
        if(arr.size()>m*n || arr.size()<m*n) return {};
        vector<vector<int>>ans;
        for(int i=0;i<arr.size();i++){
            vector<int>temp;
            for(int j=i;j<i+n;j++){
                temp.push_back(arr[j]);
            }
            ans.push_back(temp);
            i=i+n-1;
        }
        return ans;
    }
};