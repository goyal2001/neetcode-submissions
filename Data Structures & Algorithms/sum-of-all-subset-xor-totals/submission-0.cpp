class Solution {
public:
    int ans=0;
    void sum(vector<int>& nums,int i,int x){
        if(i>=nums.size()){
           ans+= x;
           return;
        }
        x = x^nums[i];
        sum(nums,i+1,x);
        x = x^nums[i];
        sum(nums,i+1,x);
    }
    int subsetXORSum(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        sum(nums,0,0);
        return ans;
    }
};