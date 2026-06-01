class Solution {
public:
    int solve(vector<int>& nums,int i,int j,vector<int>& dp){
        if(i>=j) return 0;
        if(dp[i]!=-1) return dp[i];
        int skip= solve(nums,i+1,j,dp);
        int pick = nums[i]+ solve(nums,i+2,j,dp);
        return dp[i]=max(skip,pick);
    }
    int rob(vector<int>& nums) {
        int j=nums.size();
        vector<int> dp(nums.size(),-1);
        //dp[0]=0;
    return solve(nums,0,j,dp);
    }
};
