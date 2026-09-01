class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<int> st(26,0);
        int i =0;
        while(i<s.size() && i<t.size()){
            st[s[i]-'a']++;
            st[t[i]-'a']--;
            i++;
        }
        while(i<s.size()) st[s[i++]-'a']++;
        while(i<t.size()) st[t[i++]-'a']--;
          
        for(int i=0;i<26;i++) if(st[i]!=0) return false;
        
        return true;
    }
};
