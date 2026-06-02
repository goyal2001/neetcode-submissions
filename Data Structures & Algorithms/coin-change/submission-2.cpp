class Solution {
public:
    long ways(int i,vector<int>& coins,int sum,int amount,vector<long>& dp){
        if(sum == amount) return 0;
        if(sum > amount || i>=coins.size()) return INT_MAX;
        if(dp[sum]!=-1) return dp[sum];
        long take = INT_MAX;
        if (amount - sum >= coins[i]) take = 1 + ways(i, coins, sum + coins[i], amount, dp);
        return dp[sum] = min(ways(i+1, coins, sum, amount, dp), take);
    }
    int coinChange(vector<int>& coins, int amount) {
        //if(amount==0) return 0;
        sort(coins.begin(),coins.end());
        vector<long> dp(amount+1,-1);
       long ans= ways(0,coins,0,amount,dp);
        return ans>=INT_MAX?-1:ans;
    }
};
