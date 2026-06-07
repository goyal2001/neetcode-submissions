class Solution {
public:
    void per(vector<vector<int>>&ans,vector<int>&nums,vector<bool> &a,vector<int> &out){
        if(out.size()==nums.size()){
            ans.push_back(out);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(a[i]==false){
            if(i>0 && nums[i]==nums[i-1] && !a[i-1])continue;
            a[i]=true;
            out.push_back(nums[i]);
            per(ans,nums,a,out);
            out.pop_back();
            a[i]=false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<bool>v(nums.size(),false);
        vector<int>out;
        sort(nums.begin(),nums.end());
        per(ans,nums,v,out);
        return ans;
    }
};