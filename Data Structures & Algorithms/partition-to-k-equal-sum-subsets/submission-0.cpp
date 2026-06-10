class Solution {
public:
    int target;
    bool solve(int i,vector<int>& nums,vector<int>& temp){
        // if(i==nums.size()){
        //     for(int val:temp){if(val!=0) return false;}
        //      return true;
        //      }
          
        // for(int j=0;j<temp.size();j++){
        //    if(nums[i]<=temp[j]){
        //     temp[j]-=nums[i];
        //     if(solve(i+1,nums,temp)) return true;
        //     temp[j]+=nums[i];   
        //     } 
        // }

        // return false;   
        if(i == nums.size())
        return true;

    for(int j = 0; j < temp.size(); j++) {

        if(j > 0 && temp[j] == temp[j-1])
            continue;

        if(temp[j] >= nums[i]) {

            temp[j] -= nums[i];

            if(solve(i + 1, nums, temp))
                return true;

            temp[j] += nums[i];

            // if(temp[j] == target) // bucket was empty before
            //     break;
        }
    }
    return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(nums.size()<k) return false;
        int sum=0;
        for(int i:nums) sum+=i;
        if(sum%k!=0) return false;
        sort(nums.rbegin(),nums.rend());
        vector<int> temp(k,target=sum/k);
        return solve(0,nums,temp);
    }
};