class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int x1=-1,x2=-1,cnt1=0,cnt2=0;
        //this gives majoirity 2 element  present in the nums
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=x2)  {x1=nums[i];cnt1++;}
            else if(cnt2==0 && nums[i]!=x1) {x2=nums[i];cnt2++;}
            else if(x1==nums[i]) cnt1++;
            else if(x2==nums[i]) cnt2++;
            else {cnt1--;cnt2--;}
        }
        //now x1 & x2 have majoirity element 
        cnt1=0,cnt2=0;
        for(auto i:nums){
            if(i==x1) cnt1++;
            else if(i==x2) cnt2++;
        }
        cout<<x1<<" "<<cnt1<<" "<<x2<<" "<<cnt2;
        if(cnt1>nums.size()/3) ans.push_back(x1);
        if(cnt2>nums.size()/3) ans.push_back(x2);
        return ans;
    }
};