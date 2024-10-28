class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
         unordered_set<int>st;
         for(int i=0;i<allowed.size();i++){
            st.insert(allowed[i]);
         }
         int cnt=0;
         for(auto str: words){
            int i=0;
            for(;i<str.size();i++){
                if(st.find(str[i])!=st.end()){
                    continue;
                }
                else break;
            }
            if(i==str.size()) cnt++;
         }
         return cnt;
    }
};