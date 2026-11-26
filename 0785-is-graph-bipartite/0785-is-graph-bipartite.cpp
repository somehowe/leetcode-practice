class Solution {
public:
    // we will go down and explore and change the vector
    bool dfs(int idx, int side_val, vector<vector<int>>& graph, vector<int> &side) {
        if (side[idx] != 0) {
            return side[idx] == side_val;
        }
        // thus we must now have it be 0 not assigned yet
        // now we should go as far down as we can with this idx
        side[idx] = side_val;
        for (int corr : graph[idx]) {
            // it should be place on the opposite side
            if (!dfs(corr, -side_val, graph, side)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> side(graph.size(), 0); // -1 for left, 1 for right, and 0 for unassigned
        for (int i = 0; i < graph.size(); ++i) {
            // we should only do this for unassigned nodes. because we don't 
            // want to force that it is on the riht side
            if (side[i] == 0 && !dfs(i, 1, graph, side)) return false; 
        }
        return true;
    }
};