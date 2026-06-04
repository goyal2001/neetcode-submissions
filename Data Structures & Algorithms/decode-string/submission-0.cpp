class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        stack<string> st;
        for(char a:s){
         if(a==']'){
            string temp="";
           while(st.top()!="["){
               temp = st.top()+temp;
               st.pop();
           }
           st.pop(); // ]

           string k = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    k = st.top() + k;
                    st.pop();
                }
                int repeatCount = stoi(k);
            string repeat="";
           for(int i=1;i<=repeatCount;i++){
               repeat=repeat+temp;
           }
           st.push(repeat);
         }
         else st.push(ans+a);

        }
        while(!st.empty()){
            ans= st.top()+ans;
            st.pop();
        }
        return ans;
    }
};