class Solution {
public:
int solve(int i,int n,vector<int> &dp,vector<int>& cost){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=cost[i]+min(solve(i+1,n,dp,cost), solve(i+2,n,dp,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
         vector<int> dp(n+1,-1);
       return min(solve(0,n,dp,cost),solve(1,n,dp,cost));
    }
};
