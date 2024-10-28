class Solution {
public:
    int getLucky(string s, int k) {
      
        string str="";
        for(int i=0;i<s.size();i++){
            int x = s[i]-'a' + 1;
            str+=to_string(x);
        }
        while(k--){
            int sum=0;
            for(int i=0;i<str.size();i++){
                sum+=str[i]-'0';
            }
            str=to_string(sum);
        }
        return stoi(str);
    }
};