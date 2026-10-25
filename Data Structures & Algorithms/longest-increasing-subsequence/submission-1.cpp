class Solution {
public:
    int solve(int i,int j,vector<int>& nums,int prev,vector<int>& dp){
        if(i>=j) return 0;
        if(dp[prev+1]!=-1) return dp[prev+1];
        int take = 0;
        if(prev==-1 || nums[i]>nums[prev]) take=1+ solve(i+1,j,nums,i,dp);
        int nottake=solve(i+1,j,nums,prev,dp);
        return dp[prev+1]=max(take,nottake);

    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return solve(0,nums.size(),nums,-1,dp);
    }
};
