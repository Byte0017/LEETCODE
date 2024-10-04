class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long int total=accumulate(skill.begin(),skill.end(),0);
        int n=skill.size();
        if(total%(n/2)) return -1;

        int pairSum=total/(n/2);
        long long int productSum=0;
        
        sort(skill.begin(),skill.end());
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