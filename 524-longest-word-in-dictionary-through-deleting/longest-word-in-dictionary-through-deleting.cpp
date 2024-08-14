class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans="";
        for(int it=0;it<dictionary.size();it++){
            string temp=dictionary[it];
            int i=0,j=0;

            while(i<s.size() && j<temp.size()){
                if(s[i]==temp[j]){
                    i++,j++;
                }
                else i++;
            }
            if(j==temp.size()){
                if(temp.size()>ans.size()) ans=dictionary[it];
                if(temp.size()==ans.size()){
                    //maintain lexography bcz yha glti hogi
                    if(temp<ans) ans=dictionary[it];
                }
            }
        }
        return ans;
    }
};