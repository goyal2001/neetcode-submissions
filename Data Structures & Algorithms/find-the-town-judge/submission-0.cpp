class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> truster(n+1,0);
        int judge = -1;
        for(int i=0;i<trust.size();i++) {
             truster[trust[i][1]]++;
             truster[trust[i][0]]--;
        }
        for(int i=1;i<=n;i++){
        if(truster[i]==n-1) return i;
        }
        return -1;
    }
};