class Solution {
public:
    int solve(int i,int n,vector<int> nums,vector<int> &dp){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int one= solve(i+2,n,nums,dp);
        int two= solve(i+3,n,nums,dp);
        return dp[i] = nums[i] + max(one,two);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return max(solve(0,n,nums,dp),solve(1,n,nums,dp));
    }
};
