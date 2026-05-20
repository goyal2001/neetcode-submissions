class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0) return 0;
        unordered_map<char,int> st;
        int start = 0;
        int ans = 0;
        for(int i=0;i<s.length();i++){
            if(st.find(s[i])!=st.end()){
                   start=max(start,st[s[i]]+1);
                    st[s[i]]=i;
            }else{
                st[s[i]]=i;
            }
            ans = max(ans,i-start+1);
        }
        return ans;
    }
};
