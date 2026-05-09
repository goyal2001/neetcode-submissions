class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int cand1;
        int count1=0;
        int cand2;
        int count2=0;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(cand1==nums[i])   count1++;
            else if(cand2==nums[i]) count2++;
            else if(count1==0){
                cand1=nums[i]; count1++;
            }
            else if(count2==0){
                cand2 = nums[i]; count2++;
            }  
            else{
                count1--;
                count2--;
            }
        }
        count1=0;
        count2=0;
        for(int num:nums){
            if(cand1==num) count1++;
            else if(cand2==num) count2++;
        }
        if(count1*3>n) ans.push_back(cand1);
        if(count2*3>n) ans.push_back(cand2);
        return ans;
    }
};