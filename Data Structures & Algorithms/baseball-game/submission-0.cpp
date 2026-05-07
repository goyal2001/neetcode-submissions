class Solution {
public:
   int calPoints(vector<string>& operations) {
        stack<int> st;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="+"){
              int temp1=st.top();
              st.pop();
              int temp2=st.top();
              st.push(temp1);
              st.push(temp1+temp2);
            }
            else if(operations[i]=="D"){
               int temp = st.top();  //st.pop();
               st.push(2*temp);
            }else if(operations[i]=="C"){
                  st.pop();
            }else{
                st.push(std::stoi(operations[i]));
            }
        }
        int ans=0;
        while(!st.empty()){
          ans += st.top();
          st.pop();
        }
        return ans;
    }
};