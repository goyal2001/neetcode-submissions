class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
         unordered_map<int,int> mp;
        for(int num:nums){
            if(mp.find(num)==mp.end()) mp[num]=num;
            else return true;
        }
        return false;
    }
};