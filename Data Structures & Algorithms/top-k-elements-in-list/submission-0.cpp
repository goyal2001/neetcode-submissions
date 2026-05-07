class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]=mp[nums[i]]+1;

        vector<vector<int>> freq(nums.size()+1);
        for(auto i:mp){
            freq[i.second].push_back(i.first);
        }

        vector<int> ans;
         for (int i = freq.size() - 1; i > 0; --i) {
            for (int n : freq[i]) {
                ans.push_back(n);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};
