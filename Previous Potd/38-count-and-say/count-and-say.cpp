class Solution {
public:
    void compress(string& str){
        string temp="";
        char curr=str[0];
        int cnt=1;

        for(int i=1;i<str.size();i++){
            if(str[i]==curr) cnt++;
            else{
                temp+=to_string(cnt)+curr;
                curr=str[i];
                cnt=1;
            }
        }
        temp+=to_string(cnt)+curr;

        str=temp;

    }
    string countAndSay(int n) {
        if(n==1) return "1";
        string str="1";
        n--;
        while(n--){
            compress(str);
        }
        return str;
    }
};