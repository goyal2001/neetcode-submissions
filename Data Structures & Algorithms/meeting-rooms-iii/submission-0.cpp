class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
         sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> available;

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > occupied;

        vector<int> count(n, 0);

        for (int i = 0; i < n; i++) {
            available.push(i);
        }

        for (auto& meeting : meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            long long duration = end - start;

            while (!occupied.empty() && occupied.top().first <= start) {
                available.push(occupied.top().second);
                occupied.pop();
            }

            if (!available.empty()) {
                int room = available.top();
                available.pop();

                occupied.push({end, room});
                count[room]++;
            } else {
                auto [freeTime, room] = occupied.top();
                occupied.pop();

                occupied.push({freeTime + duration, room});
                count[room]++;
            }
        }

        int ans = 0;

        for (int i = 1; i < n; i++) {
            if (count[i] > count[ans]) {
                ans = i;
            }
        }

        return ans;
    }
};