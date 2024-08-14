class Solution {
public:
    //Recursive code
    // int solve(int n){
    //     if(n==2) return 2;
    //     if(n==1) return 1;
    //     return solve(n-1) + solve(n-2);
    // }

    //top to bottom solution
    int Memoisation(int n,vector<int>&dp){
        //base case
        if(n==0 || n==1) return 1;
        //check in dp array
        if(dp[n]!=-1) return dp[n];
        dp[n]=Memoisation(n-1,dp)+Memoisation(n-2,dp);
        return dp[n];
    }

    // //Bottom Up Approach
    // int Tabulation(int n,vector<int>&dp){
    //     if(n==0 || n==1) return 1;
    //     dp[0]=1,dp[1]=1;

    //     for(int i=2;i<=n;i++){
    //         dp[i]=dp[i-1]+dp[i-2];
    //     }
    //     return dp[n];
    // }

    // // Space Optimisation
    // int spaceOptim(int n){
    //     if(n==0 || n==1) return 1;
    //     int prev1=1,prev2=1;
    //     int curr;

    //     for(int i=2;i<=n;i++){
    //         curr=prev1+prev2;
    //         prev2=prev1;
    //         prev1=curr;
    //     }
    //     return curr;
    // }
    
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        // return solve(n); 
        return Memoisation(n,dp);
        // return Tabulation(n,dp);
        // return spaceOptim(n);
    }
};
