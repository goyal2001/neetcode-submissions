class Solution {
public:
    int directions[4][2] = {{1, 0}, {-1, 0},
                            {0, 1}, {0, -1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 0) {
                    bfs(grid, r, c);
                }
            }
        }

    }

    void bfs(vector<vector<int>>& grid, int r, int c) {
        queue<pair<int, int>> q;
        q.push({r, c});
        int count = 1;
        int qsize=1;
        while (!q.empty()) {
            auto node = q.front();q.pop();
            int row = node.first, col = node.second;
            for (int i = 0; i < 4; i++) {
                int nr = row + directions[i][0];
                int nc = col + directions[i][1];
                if (nr >= 0 && nc >= 0 && nr < grid.size() &&
                    nc < grid[0].size() && grid[nr][nc]==INT_MAX) {
                    q.push({nr, nc});
                    grid[nr][nc] = count;
                }
                else if(nr >= 0 && nc >= 0 && nr < grid.size() &&
                    nc < grid[0].size() && grid[nr][nc]>0 && grid[nr][nc]>count){
                    q.push({nr, nc});
                    grid[nr][nc] = min(grid[nr][nc],count);
                }
            }
            qsize--;
            if(qsize==0){
                count++;
                qsize=q.size();
            }

        }
    }
};
