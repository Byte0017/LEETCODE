// class Solution {
// public:
//     bool check(string& s,int j){
//         int i=0;
//         while(i<=j){
//             if(s[i]!=s[j]) return false;
//             i++,j--;
//         }
//         return true;
//     }
//     string shortestPalindrome(string s) {
//         int n=s.size();
//         string temp="";
//         for(int i=n-1;i>=0;i--){
//             if(!check(s,i)){
//                 temp=temp+s[i];
//             }
//             else break;
//         }
//         temp=temp+s;
//         return temp;
//     }
// };

//M:2 Efficient approach
class Solution {
public:
    string shortestPalindrome(string s) {
        string temp="";
        string t1,t2;

        int i=0,j=s.size()-1;

        while(i<j){
            t1.push_back(s[i]);
            t2.push_back(s[j]);

            if(t1==t2) {
                i++,j--;
                continue;
            }
            else{
               //pop() in t1 from back and in t2 from front
               while(t1!=t2){
                   temp+=t2[0];
                   t1.pop_back();
                   t2=t2.substr(1);
               }
               //update i and j
               j--;
               i=t2.size();
            }
        }
        temp=temp+s;
        return temp;
    }
};