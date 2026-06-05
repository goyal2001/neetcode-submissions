class Solution {
public:

    bool findsum(vector<int>& nums,int i,int target,int j){
        if(i>=j || target<0) return false;
        if(target==0) return true;

        return findsum(nums,i+1,target-nums[i],j) || findsum(nums,i+1,target,j);
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums) sum+=num;
        if(sum%2!=0) return false;

        return findsum(nums,0,sum/2,nums.size());
    }
};
