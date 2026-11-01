class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // go through till the next idx is greater than or equal to our first
        vector<vector<int>> output;
        int idx = 0;
        while (idx < intervals.size()) {
            if (intervals[idx][1] >= newInterval[0]) break;
            output.push_back(intervals[idx++]);
        }
        // two cases: either add it right away or not 
        if (idx >= intervals.size() || newInterval[1] < intervals[idx][0]) {
            output.push_back(newInterval);
        } else {
            // there is some intersection
            int start = min(newInterval[0], intervals[idx][0]);
            int end = max(newInterval[1], intervals[idx][1]);
            while (idx < intervals.size()) {
                if (newInterval[1] < intervals[idx][0]) break;
                end = max(end, intervals[idx++][1]);
            }
            output.push_back({start, end});
        }
        // now the final stage for the rest of them
        while (idx < intervals.size()) {
            output.push_back(intervals[idx++]);
        }
        return output;
    }
};