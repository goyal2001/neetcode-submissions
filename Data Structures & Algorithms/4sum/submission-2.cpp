class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        for(int i=0;i<nums.size()-3;i++){
             if (nums[i] > target) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for(int j=i+1;j<nums.size()-2;j++){ 
                if (nums[i]+nums[j] > target) break;
                if (j-1 > i && nums[j] == nums[j - 1]) continue;
            int l = j + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[j] + nums[l] + nums[r];
                if (sum > target) {
                    r--;
                } else if (sum < target) {
                    l++;
                } else {
                    res.push_back({nums[i],nums[j], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;           
            }
            }
        }
        }

        return res;
    }
};