class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     vector<int> ans(nums.size(),0);
     int product = 1;
     int noOfZeros = 0;
     for(int num: nums){
        if(num==0){
           noOfZeros++; 
        }else{
product = product * num;
        }
     }
     if(noOfZeros>1){
         return ans;
     }
    for(int i=0;i<nums.size();i++){
        if(nums[i]==0){
            ans[i]=product;
        }
        else if(nums[i]!=0 && noOfZeros==1){
            ans[i]=0;
        }
        else{
            ans[i] = product/nums[i];
        }
    }
     return ans;
    }
};
