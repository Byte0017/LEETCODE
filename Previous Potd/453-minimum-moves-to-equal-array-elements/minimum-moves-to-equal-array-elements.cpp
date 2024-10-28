class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int step=0;
        int carry=0;
        for(int i=0;i<nums.size()-1;i++){
            carry=nums[i+1]-nums[i]+carry;
            step+=carry;
        }
        return step;
    }
};