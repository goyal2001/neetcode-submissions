class Solution {
public:

    int findsum(vector<int>& nums,int i,int target,int j,vector<vector<int>>& dp){
        if(i>=j && target!=0) return 0;
        if(target<0) return 0;
        if(target==0) return 1;

        if(dp[i][target]!=-1) return dp[i][target];
        return dp[i][target]=findsum(nums,i+1,target-nums[i],j,dp) || findsum(nums,i+1,target,j,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums) sum+=num;
        if(sum%2!=0) return false;
        vector<vector<int>> dp(nums.size(), vector<int>(sum / 2 + 1, -1));
        return findsum(nums,0,sum/2,nums.size(),dp);
    }
};
