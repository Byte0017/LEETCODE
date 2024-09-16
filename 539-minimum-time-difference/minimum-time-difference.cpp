class Solution {
public:
    int findMinDifference(vector<string>& time) {
        vector<int>v;
        for(int i=0;i<time.size();i++){
            int h=stoi(time[i].substr(0,2))*60;
            int m=stoi(time[i].substr(3,2));
            v.push_back(h+m);
        }
        sort(v.begin(),v.end());
        
        int minDiff=INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            int t=v[i+1]-v[i];
            if(t>720) t=abs(1440-v[i+1]+v[i]);
            minDiff=min(minDiff,t);
        }
        //check last and first pair
        int t=v[v.size()-1]-v[0];
        if(t>720) t=abs(1440-v[v.size()-1]+v[0]);
        minDiff=min(minDiff,t);

        return minDiff;
    }
};