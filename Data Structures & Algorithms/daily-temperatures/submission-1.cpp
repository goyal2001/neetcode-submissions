class Solution {
public:
     vector<int> dailyTemperatures(vector<int>& temp) {
    int n = temp.size();
    vector<int> ans(n, 0);
    stack<pair<int, int>> st; // {temperature, index}

    for (int i = n - 1; i >= 0; i--) {
        // Remove all temperatures that are <= current temp
        while (!st.empty() && st.top().first <= temp[i]) {
            st.pop();
        }

        // If stack is not empty, top is the next warmer day
        if (!st.empty()) {
            ans[i] = st.top().second - i;
        }

        // Push current temperature with index
        st.push({temp[i], i});
    }

    return ans;
}
};
