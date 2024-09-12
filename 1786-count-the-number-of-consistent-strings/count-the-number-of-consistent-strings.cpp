class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
         unordered_map<int,int>mp;
         for(int i=0;i<allowed.size();i++){
            mp[allowed[i]]++;
         }
         int cnt=0;
         for(auto str: words){
            int i=0;
            for(;i<str.size();i++){
                if(mp.find(str[i])!=mp.end()){
                    continue;
                }
                else break;
            }
            if(i==str.size()) cnt++;
         }
         return cnt;
    }
};