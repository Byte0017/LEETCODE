class Solution {
public:
    int dominent(vector<int>& nums){
        int x=-1,cnt=0;
        //this gives the majoirity element
        for(int i=0;i<nums.size();i++){
            if(cnt==0) {x=nums[i]; cnt++;}
            else if(x==nums[i]) cnt++;
            else cnt--;
        }
        //Now find the count of majority element
        int count=0;
        for(auto i:nums) if(i==x) count++;
        if(count>nums.size()/2) return x; else return -1;
    }
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return -1;
        int d=dominent(nums);
        if(d==-1) return -1;

        // Step 2: Traverse and check the prefix & suffix counts
        int prefixCount = 0, total=0;
        for (int num : nums) {
            if (num==d) total++;
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == d) prefixCount++;
            if (prefixCount > (i + 1) / 2 && 
                (total-prefixCount)>(n-i-1)/2){
                return i;
            }
        }
        return -1; 
    }
};