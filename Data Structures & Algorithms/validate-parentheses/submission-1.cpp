class Solution {
public:
    bool isValid(string s) {
        if(s[0] == ')' || s[0] == ']' || s[0] == '}') return false; 
        int i = 0, n = s.length();
        if(n & 1) return false;
        
        stack<char> stk ;
        while(n--){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') stk.push(s[i]);
            else if(stk.empty() && (s[i] == ')' || s[i] == ']' || s[i] == '}')) return false;
            else {
                if((s[i] == ')' && stk.top() == '(') || (s[i] == ']' && stk.top() == '[') || (s[i] == '}' && stk.top() == '{')) stk.pop();
                else return false;
            }
            i++;
        }
        
        if(stk.empty()) return true;
        return false ;
    }
};
