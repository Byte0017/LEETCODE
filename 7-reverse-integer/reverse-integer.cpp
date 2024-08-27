class Solution {
public:
    int reverse(int x) {
      long long int rev=0;
      while(x!=0){
        rev=rev*10+x%10;
        if(rev>INT_MAX) return 0;
        if(rev<INT_MIN) return 0;
        x=x/10;
      }
      return rev;
    }
};