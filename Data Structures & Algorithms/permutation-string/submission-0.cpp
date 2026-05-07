class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;

        vector<int> s1ct(26,0);
        vector<int> s2ct(26,0);
        for(int i=0;i<s1.length();i++){
            s1ct[s1[i] - 'a']++;
            s2ct[s2[i] - 'a']++;
        }
        int matches = 0;
        for(int i=0;i<26;i++){
            if(s1ct[i]==s2ct[i]) matches++;
        }
        if(matches==26) return true;

        int l=0;
        for(int r=s1.length();r<s2.length();r++){
            if(matches==26) return true;

            int idx = s2[r] - 'a';
            s2ct[idx]++;
            if (s1ct[idx] == s2ct[idx]) {
                matches++;
            } else if (s1ct[idx] + 1 == s2ct[idx]) {
                matches--;
            }

            idx = s2[l] - 'a';
            s2ct[idx]--;
            if (s1ct[idx] == s2ct[idx]) {
                matches++;
            } else if (s1ct[idx] - 1 == s2ct[idx]) {
                matches--;
            }
            l++;

        }

        return matches==26;
    }
};
