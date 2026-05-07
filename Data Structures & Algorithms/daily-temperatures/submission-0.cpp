class Solution {
public:
     vector<int> dailyTemperatures(vector<int>& temp) {
       int n=temp.size();
        vector<int> ans(n,0);
        stack<int> s; int j=n-1;
        s.push(j--);
        while(!s.empty() && j>=0){
            if(temp[j]<temp[s.top()]){
                ans[j]=s.top()-j;
            }
            else{
                while(!s.empty() && temp[j]>=temp[s.top()]){
                    s.pop();
                }
                if(s.empty()){
                    ans[j]=0;
                }
                else{
                    ans[j]=s.top()-j;
                }
            }
            s.push(j--);
        }
        
        return ans;
    }
};
