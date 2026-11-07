class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int count = 0;
        int idx = 0;
        while (idx < points.size()) {
            ++count; // we need one balloon to pop this one and maybe some others
            int curr_end = points[idx][1];
            ++idx;
            while (idx < points.size() && curr_end >= points[idx][0]) {
                curr_end = min(curr_end, points[idx][1]); // because that is the 
                // end to where we could shoot the arrow basically
                ++idx;
            }
        }
        return count;
    }
};