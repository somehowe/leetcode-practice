class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // bfs
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        constexpr int dx[] = {-1, -1, -1, 1, 1, 1, 0, 0};
        constexpr int dy[] = {-1, 1, 0, -1, 1, 0, 1, -1};
        if (grid[0][0] == 0) q.push({0, 0});
        grid[0][0] = -1; // mark that we have visited it
        int path_cnt = 1; // just being on the first on is one
        while (!q.empty()) {
            int curr_size = q.size();
            // go through each of these
            // -1 for already visited
            for (int i = 0; i < curr_size; ++i) {
                const auto curr_front = q.front();
                q.pop();
                if (curr_front.first == n - 1 && curr_front.second == m - 1) return path_cnt;
                // now we should loook around it to see what to add to the q
                for (int j = 0; j < 8; ++j) {
                    int cx = curr_front.first + dx[j];
                    int cy = curr_front.second + dy[j];
                    if (cx >= 0 && cy >= 0 && cx < n && cy < m && grid[cx][cy] == 0) {
                        grid[cx][cy] = -1; // we can't revisit it
                        q.push({cx, cy});
                    }
                }
            }
            ++path_cnt; // we finished this level
        }
        return -1;
    }
};