class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
         for(int i=0;i<=k && i<nums.size();i++){
              if(mp.find(nums[i])!=mp.end()) { return true;}
              else mp[nums[i]]=1; 
         }

         //if(mp.size()!=k+1) return true;

            int i=0;
            for(int j=k+1;j<nums.size();j++){
              if(mp.find(nums[j])!=mp.end()) mp[nums[j]]+=1;
              else mp[nums[j]]=1; 

              mp[nums[i]]--;
              if(mp[nums[i]]==0) mp.erase(nums[i]); 
              if(mp.size()!=k+1) return true;
              i++;
            }
        //}
        return false;
    }
};