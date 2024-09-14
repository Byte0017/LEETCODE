class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int maxValue = *max_element(nums.begin(), nums.end());
        int maxLength = 0, currLength = 0;
      
        for (int value : nums) {
            if (value == maxValue) {
               currLength++;
               maxLength =max(maxLength, currLength);
            } else {
                // Reset current subarray length if the current element is not the maximum value.
                currLength = 0;
            }
        }
       
        return maxLength;
    }
};