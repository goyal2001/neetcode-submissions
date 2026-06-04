class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr_max = 1;
        int curr_min = 1;
        int ans = INT_MIN;
        for (int num : nums) {
            if (num < 0) swap(curr_max, curr_min);
            curr_max = max(num, curr_max * num);
            curr_min = min(num, curr_min * num);
            ans = max(ans, curr_max);
        }
        return ans;
    }
};
