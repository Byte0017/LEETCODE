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
// class Solution {
// public:
//     string shortestPalindrome(string s) {
//         string temp="";
//         string t1,t2;

//         int i=0,j=s.size()-1;

//         while(i<j){
//             t1.push_back(s[i]);
//             t2.push_back(s[j]);

//             if(t1==t2) {
//                 i++,j--;
//                 continue;
//             }
//             else{
//                while(t1!=t2){
//                    temp+=t2[0];
//                    //pop() in t1 from back and in t2 from front
//                    t1.pop_back();
//                    t2.erase(0, 1);
//                }
//                //update i and j
//                j--;
//                i=t2.size();
//             }
//         }
//         temp=temp+s;
//         return temp;
//     }
// };

//M3
class Solution {
public:
    string shortestPalindrome(string s) {
       string rev=s;
       reverse(rev.begin(),rev.end());

       //    int index=-1;
       int n=s.size();
       for(int i=0;i<n;i++){
        //    string str1=s.substr(0,n-i);
        //    string str2=rev.substr(i,n-i);

        //    if(str1==str2){
        //       index=i-1; 
        //       break;
        //    }

              if(!memcmp(s.c_str(),rev.c_str()+i,n-i)){
                 return rev.substr(0,i)+s;
              }  
       }
       return rev+s;
    }
};