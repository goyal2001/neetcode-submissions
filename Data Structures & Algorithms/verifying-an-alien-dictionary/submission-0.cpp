class Solution {
public:
    bool solve(int i,vector<string>& words, unordered_map<char,int> mp){
         int m = words[i-1].size();
         int n = words[i].size();
         for(int k=0;k<min(m,n);k++){
            if(mp[words[i-1][k]]==mp[words[i][k]]) continue;
            else if(mp[words[i-1][k]]<mp[words[i][k]]) return true;
            else return false;
         }
         if(m<=n) return true;
         return false;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        
        unordered_map<char,int> mp;
        for(int i=0;i<order.size();i++){
            mp[order[i]]=i+1;
        }
        bool ans = true;
        for(int i=1;i<words.size();i++){
            ans = ans & solve(i,words,mp);
            if(!ans) return ans;
        }
        return ans;
    }
};