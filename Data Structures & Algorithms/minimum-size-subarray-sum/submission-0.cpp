class Solution {
public:
      int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int i =0;
        int j=0;
        int sum = 0;
        while(i<nums.size()){
         sum+= nums[i];
         while(sum>=target){
          ans= min(ans,i-j+1);
          sum = sum- nums[j++];
         }
         i++;
        }
        return ans==INT_MAX?0:ans;
    }  
    
};