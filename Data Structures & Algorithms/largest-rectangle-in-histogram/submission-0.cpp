class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n,-1);
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[i]<=heights[st.top()])
             st.pop();

            if(!st.empty())  left[i] = st.top();
                            
             st.push(i);
        }

        while (!st.empty()) st.pop();
        
        vector<int> right(n, n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            left[i] += 1;
            right[i] -= 1;
            maxArea = max(maxArea, heights[i] * (right[i] - left[i] + 1));
        }

        return maxArea;

    }
};
