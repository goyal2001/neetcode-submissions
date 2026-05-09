class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
       int cand = nums[0];
       for(int i=1;i<nums.size();i++){
             if(cand!=nums[i]){
                if(count==0) { cand=nums[i]; count=1;}
                else count--;
             }
             else count++;
       }
       return cand;
    }
};