class Solution {
public:
bool solve(int i,int j,int m,int n,int idx,vector<vector<char>>& board, string& word){
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[idx]) return false;
        if (idx == word.size() - 1) return true;
        
        char temp = board[i][j];
        board[i][j] = '#';

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        for (int d = 0; d < 4; d++) {

            int nr = i + dx[d];
            int nc = j + dy[d];

            if (solve(nr, nc,m,n, idx + 1, board, word)) {
                board[i][j] = temp;
                return true;
            }
        }
         board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && solve(i, j, m, n, 0, board, word)) return true;
            }
        }
        return false;
    }
};
