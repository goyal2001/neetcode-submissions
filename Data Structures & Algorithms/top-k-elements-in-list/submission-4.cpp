class Solution {
public:
    struct CompareSecondMin {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        // Returns true if 'a' has a lower priority (is larger) than 'b'
        return a.second > b.second; 
    }
};

struct CompareSecondMax {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        // Returns true if 'a' has a lower priority than 'b'
        return a.second < b.second; 
    }
};

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
        // vector<int> ans;
        // priority_queue<pair<int, int>, vector<pair<int, int>>, CompareSecondMin> maxPq;
        // unordered_map<int,int> mp;
        // for(int n:nums){
        //     if(mp.find(n)!=mp.end()) mp[n]++;
        //     else mp[n]=1;
        // }
        // for(auto m:mp){
        //     maxPq.push({m.first,m.second});
        //     if(maxPq.size()>k) maxPq.pop();
        // }
        // while(k>0){ ans.push_back(maxPq.top().first); maxPq.pop(); k--;}
        // return ans;
    }
};
