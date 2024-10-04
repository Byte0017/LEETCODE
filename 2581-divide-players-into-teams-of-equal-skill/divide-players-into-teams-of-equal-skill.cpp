class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(),skill.end());
        int pairSum=skill[0]+skill[n-1];
        
        long long int productSum=0;
        
        int i=0;
        int j=n-1;
        while(i<j){
            if(skill[i]+skill[j]==pairSum){
                productSum+=skill[i]*skill[j];
                i++,j--;
            }
            else return -1;
        }
        return productSum;

    }
};