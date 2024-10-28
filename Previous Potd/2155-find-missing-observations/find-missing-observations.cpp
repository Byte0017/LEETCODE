class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        vector<int>ans;
        int m=rolls.size();
        int total=(m+n)*mean;
        for(auto i:rolls) total-=i;

        //divide total into n parts
        
        if(total<n || total>n*6) return {};
        
       
        int x=total/n;
        int y=total%n;
        for(int i=0;i<n;i++){
            if(y>0){
              ans.push_back(x+1);
              y--;
            }
            else{
                ans.push_back(x);
            } 
            total-=x;
        }
        return ans;
    }
};