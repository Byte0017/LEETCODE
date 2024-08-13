class Solution {
public:
void solve(vector<int>&candidates,int target,vector<int>&v,vector<vector<int>>&ans,int index){
    //base Case
    if(target==0){
        ans.push_back(v);
        return;
    }
    if(target<0){
        return;
    }
    for(int i=index;i<candidates.size();i++){
        if(i>index && candidates[i]==candidates[i-1]) continue;
        v.push_back(candidates[i]);
        solve(candidates,target-candidates[i],v,ans,i+1);
        v.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
        solve(candidates,target,v,ans,0);
       
        return ans;
    }
};