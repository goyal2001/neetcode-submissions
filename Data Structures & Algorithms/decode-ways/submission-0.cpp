class Solution {
public:
    int ways(int i,int n,string s,vector<int> &dp){
        if(i==n) return 1;
        else if(s[i]==48) return 0;
        if(dp[i]!=-1) return dp[i];
        int duble = 0;
        if(i<n-1 && ((s[i]<=49) || (s[i]==50 && s[i+1]<=54))){
         duble = ways(i+2,n,s,dp);
        }
        int single = ways(i+1,n,s,dp);
         return dp[i]=single + duble;
    }
    int numDecodings(string s) {
        if(s[0]==48) return 0;
        vector<int> dp(s.size(),-1);
        return ways(0,s.size(),s,dp);
    }
};
