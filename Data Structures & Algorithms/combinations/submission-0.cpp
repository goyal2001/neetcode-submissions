class Solution {
public:
    vector<vector<int>> ans;
    void solve(int n,int k,int i,vector<int> &temp){
        if(temp.size()==k){ans.push_back(temp);
            return;}
    
        if(temp.size()>k) return;
        if(i>n) return;
        
        temp.push_back(i);
        solve(n,k,i+1,temp);
        temp.pop_back();
        solve(n,k,i+1,temp);

    }
    vector<vector<int>> combine(int n, int k) {
        ans.clear();
        vector<int> temp;
        solve(n,k,1,temp);
        return ans;
    }
};