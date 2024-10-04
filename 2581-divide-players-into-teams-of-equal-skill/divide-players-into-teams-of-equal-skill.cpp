class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long int total=accumulate(skill.begin(),skill.end(),0);
        int size=skill.size();
        if(total%(size/2)) return -1;

        int pairSum=total/(size/2);
        long long int productSum=0;
        
        sort(skill.begin(),skill.end());
        int i=0;
        int j=size-1;
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