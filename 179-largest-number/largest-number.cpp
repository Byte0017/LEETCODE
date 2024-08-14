// class Solution {
// public:
//     string largestNumber(vector<int>& nums) {
//         string ans="";
//         for(int i=0;i<nums.size();i++){
//             string s=to_string(nums[i]);
//             ans=ans+s;
//         }
//         sort(ans.rbegin(),ans.rend());
//         return ans;  
//     }
// };
class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    string ans;

    ranges::sort(nums, [](int a, int b) {
      return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    });

    for (const int num : nums)
      ans += to_string(num);

    return ans[0] == '0' ? "0" : ans;
  }
};