class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0; int j=nums.size()-1;
        vector<int> ans;
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<nums.size();i++){ 
            mp[nums[i]].push_back(i);
            if(mp.find(target-nums[i])!=mp.end() && mp[target-nums[i]][0]!=i){
                ans.push_back(mp[target-nums[i]][0]);
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};
