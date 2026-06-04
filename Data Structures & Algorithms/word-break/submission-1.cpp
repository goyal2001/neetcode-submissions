class Solution {
public:
    bool solve(string s,int i,unordered_set<string> &words,vector<int> &dp){
        if(i>=s.size()) return true;
        
        if(dp[i]!=-1) return dp[i];

        for (int end = i; end < s.size(); end++) {
        string cur = s.substr(i, end - i + 1);

        if (words.count(cur) &&
            solve(s,end + 1 , words, dp)) {
            return dp[i] = 1;
        }
    }
        return  dp[i]=0;
         
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(),-1);
        //for(string word:wordDict) words[word]=true;
        return solve(s,0,words,dp);
    }
};
