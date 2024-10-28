class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        
       
        if(s.size()==1) return num;
       
        for(int i=0;i<s.size()-1;i++){
            int max=i;
            for(int j=i+1;j<s.size();j++){
                if(s[max]<=s[j]){
                    max=j;
                }
            }
           
            if(max!=i && s[max]!=s[i]){
                swap(s[i],s[max]);
                break;
            }  
         }
        return stoi(s);
    }
};