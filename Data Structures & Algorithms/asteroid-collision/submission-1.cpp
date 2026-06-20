class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            // if st empty or top<0 negative direction
         if(st.empty() || st.top()<0 || asteroids[i]>0) st.push(asteroids[i]);
         else{
            // if top>0 and curr is >0 same dirn
            // if(asteroids[i]>0) st.push(asteroids[i]);
            // else{
            //     // if top>0 and curr is <0
            //     while(!st.empty() && st.top()>0 ){
            //       if(abs(st.top())==abs(asteroids[i])) { st.pop(); break;}
            //       else if(abs(st.top())<abs(asteroids[i]))  st.pop();
            //       else break;
            //     }
            // }

             while(!st.empty() && st.top() > 0 && st.top() < -asteroids[i])
                    st.pop();
    
            if(st.empty() || st.top() < 0) st.push(asteroids[i]);
            else if(st.top() == -asteroids[i]) st.pop();
    
         }
        }
        vector<int> ans(st.size());
        int n=st.size()-1;
        while(!st.empty()){
          ans[n--]=st.top();
          st.pop();
        }
        return ans;
    }
};