class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r){
            int mid = (l+r)/2;
            if(nums[l] == nums[mid] && nums[r] == nums[mid]){
                l++;
                r--;
            }
            else if(nums[mid] > nums[r]){
                l = mid+1;
            }
            else{
                r = mid;
            }
        }
        return nums[l];
    }
};