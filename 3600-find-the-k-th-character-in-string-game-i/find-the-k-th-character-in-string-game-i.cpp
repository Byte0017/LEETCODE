class Solution {
public:
    char kthCharacter(int k) {
        int t=k;
        string str="a";
        while(t--){
            string temp="";
            for(int i=0;i<str.size();i++){
                if(str[i]=='z'){
                    temp.push_back('a');
                }
                else{
                    temp.push_back(str[i]+1);
                }
            }
            str+=temp;
            if(str.size()>=k){
                break;
            }
        }
       
        return str[k-1];
    }
};