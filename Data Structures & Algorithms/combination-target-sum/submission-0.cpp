class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& candidates, int sum,vector<int>& help,int i){
      if(i>= candidates.size()) return;
      if(sum<0) return;
      if(sum==0) { ans.push_back(help); return;}
      
      help.push_back(candidates[i]);
      solve(candidates,sum-candidates[i],help,i);

      help.pop_back();
      solve(candidates,sum,help,i+1);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
       sort(candidates.begin(),candidates.end());
       vector<int> help;
       solve(candidates,target,help,0);
        return ans;
    }
};
