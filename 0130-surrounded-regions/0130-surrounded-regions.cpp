class Solution {
public:
    void explore(vector<vector<char>> &board, int i, int j) {
        board[i][j] = '#';
        static constexpr int di[] = {-1, 1, 0, 0};
        static constexpr int dj[] = {0, 0, -1, 1};
        for (int l = 0; l < 4; ++l) {
            int ni = i + di[l];
            int nj = j + dj[l];
            if (ni >= 0 && nj >= 0 && ni < board.size() && nj < board[0].size() && board[ni][nj] == 'O') {
                explore(board, ni, nj);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        // explore ones that are connected to edge and mark them with #
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O' && (i == 0 || i == m - 1 || j == 0 || j == n - 1)) {
                    explore(board, i, j);
                }
            }
        }
        // now we go through and all the # we put to O's because they safe
        // and all the O's we turn to X b/c we know they ain't safe
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};