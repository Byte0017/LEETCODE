class Solution {
public:
    int majorityElement(vector<int>& nums) {
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
        cout<<x<<" "<<count<<endl;
        
        if(count>nums.size()/2) return x; else return -1;
    }
};