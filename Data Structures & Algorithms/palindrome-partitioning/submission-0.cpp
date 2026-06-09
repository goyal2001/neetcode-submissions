class Solution {
public:
    bool palindrome(string s,int i,int j){
        while(i<j){
         if(s[i++]!=s[j--]) return false;
        }
        return true;
    }
    void solve(int i,int n,string s,vector<string>& path,vector<vector<string>>& ans){
         if(i==n) {
            ans.push_back(path); return;
            }
         
        for (int end = i + 1; end <= n; ++end) {
            if (palindrome(s, i, end - 1)) {
                path.push_back(s.substr(i, end - i));
                // Recur to find other partitions
                solve(end,n, s,path, ans);
                // Backtrack to explore other partitions
                path.pop_back();
            }
        }
        return;

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(0,s.size(),s,path,ans);
        return ans;
    }
};
