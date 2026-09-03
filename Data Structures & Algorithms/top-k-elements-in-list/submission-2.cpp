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
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>, CompareSecondMax> maxPq;
        unordered_map<int,int> mp;
        for(int n:nums){
            if(mp.find(n)!=mp.end()) mp[n]++;
            else mp[n]=1;
        }
        for(auto m:mp){
            maxPq.push({m.first,m.second});
        }
        while(k>0){ ans.push_back(maxPq.top().first); maxPq.pop(); k--;}
        return ans;
    }
};
