// class Solution {
// public:
//     string findLongestWord(string s, vector<string>& dictionary) {
//         string ans="";
//         sort(s.begin(),s.end());
//         for(int it=0;it<dictionary.size();it++){
//             string temp=dictionary[it];
//             sort(temp.begin(),temp.end());
//             int i=0,j=0;

//             while(i<s.size() && j<temp.size()){
//                 if(s[i]==temp[j]){
//                     i++,j++;
//                 }
//                 else i++;
//             }
//             if(j==temp.size()){
//                 if(temp.size()>ans.size()) ans=dictionary[it];
//                 // if(temp.size()==ans.size()){
//                 //     //maintain lexography bcz yha glti hogi
//                 //     if(temp<ans) ans=dictionary[it];
//                 // }
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans = "";
        for (string& a : dictionary)
            if (check(s, a) && (ans.size() < a.size() || (ans.size() == a.size() && a < ans)))
                ans = a;
        return ans;
    }

    bool check(string& a, string& b) {
        int m = a.size(), n = b.size();
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (a[i] == b[j]) ++j;
            ++i;
        }
        return j == n;
    }
};