class Solution {
public:
    int myAtoi(string s) {
       int n=s.size();
       int i=0;
       long long int x=0;
       bool minus=false;
       
       while(i<n){
          //whitespace
          if(s[i]==' ') i++;
          else if(s[i]=='-'){
            minus=true;
            i++ ; 
            break;
          }
          else if(s[i]=='+'){
            i++ ; 
            break;
          }
          else {
            break;
          }
       }

       if(minus){
          while(i<n){
            if(s[i]>='0' && s[i]<='9'){
              x=x*10-(s[i]-'0');
              if(x<INT_MIN) return INT_MIN;
            }
            else break;
            i++;
          }
       }
       
       while(i<n){
          if(s[i]>='0' && s[i]<='9'){
              x=x*10+s[i]-'0';
              if(x>INT_MAX) return INT_MAX;
          }
          else break;
          i++;
       }
    
       return x;
    }
};