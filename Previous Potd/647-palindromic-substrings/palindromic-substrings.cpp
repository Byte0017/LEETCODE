class Solution {
public:
// int expandAroundIndex(string s,int i,int j){
//   int count=0;
//   while(i>=0 && j<s.length() &&s[i]==s[j]){
//     count++;
//     i--;
//     j++;
//   }
//   return count;
// }
    bool isPallindrome(string&s,int i,int j){
        while(i<=j){
            if(s[i]==s[j]){
                i++,j--;
            }
            else return false;
        }
        return true;
    }
    int countSubstrings(string s) {
      int count=s.size();
    //   int n=s.length();

    //   for(int i=0;i<n;i++){
    //     //odd
    //     int oddAns=expandAroundIndex(s,i,i);
    //     count=count+oddAns;

    //     //even
    //     int evenAns=expandAroundIndex(s,i,i+1);

    //     count=count+evenAns;
    //   }
    //     return count;
          for(int i=0;i<s.size()-1;i++){
              for(int j=i+1;j<s.size();j++){
                if(isPallindrome(s,i,j)) count++;
              }
          }
          return count;
    }
};
