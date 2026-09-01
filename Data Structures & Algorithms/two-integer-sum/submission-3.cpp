class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2,0);
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.find(target-nums[i])!=mp.end()){
                ans[0]=mp[target-nums[i]];
                ans[1]=i;
            }else mp[nums[i]]=i;
        }
        return ans;
    }
};
