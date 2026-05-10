class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int sum,vector<int>& help,int idx){
      if(sum == 0) {
            ans.push_back(help);
            return;
        }

        for(int i=idx; i<candidates.size(); i++) {
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > sum) break;
                
            help.push_back(candidates[i]);
            solve(candidates, sum-candidates[i],help, i+1);
            help.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
       ans.clear();
       sort(candidates.begin(),candidates.end());
       vector<int> help;
       solve(candidates,target,help,0);
       return ans;
    }
};
