class Solution {
public:
    void dfs(const vector<vector<int>> &heights, vector<vector<bool>> &pac, int i, int j) {
        static int di[] = {-1, 1, 0, 0};
        static int dj[] = {0, 0, -1, 1};
        // mark as true
        if (pac[i][j]) return;
        pac[i][j] = true;
        for (int k = 0; k < 4; ++k) {
            int ci = i + di[k];
            int cj = j + dj[k];
            if (ci >= 0 && cj >= 0 && ci < heights.size() && 
                cj < heights[0].size() && heights[ci][cj] >= heights[i][j]) {
                dfs(heights, pac, ci, cj);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> output;
        int n = heights.size();
        int m = heights[0].size();
        // let's create two arays that tell us if that cell can reach pac
        vector<vector<bool>> pac(n, vector<bool>(m, false)); //
        vector<vector<bool>> atl(n, vector<bool>(m, false));
        pac[0][0] = true;
        atl[n - 1][m - 1] = true;
        for (int i = 1; i < n; ++i) {
            dfs(heights, pac, i, 0);
            dfs(heights, atl, n - 1 - i, m - 1);
        }
        for (int j = 1; j < m; ++j) {
            dfs(heights, pac, 0, j);
            dfs(heights, atl, n - 1, m - 1 - j);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (pac[i][j] && atl[i][j]) {
                    output.push_back({i, j});
                }
            }
        }
        return output;
    }
};