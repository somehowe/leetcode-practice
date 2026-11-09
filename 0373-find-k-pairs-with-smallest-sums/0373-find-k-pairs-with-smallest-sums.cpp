class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // map sum to the two idx's where we found it
        // sum, idx1, idx2
        using Entry = array<int, 3>;
        priority_queue<Entry, vector<Entry>, greater<Entry>> sum_to_idxs;
        sum_to_idxs.push({nums1[0] + nums2[0], 0, 0});
        vector<vector<int>> output;
        // thus our priority queue can be of size only of size k because whenever we show 
        // our two options we always choose one of them so priority queue will only increase
        // by one or less on each iteration and insertion takes log so this is safe.
        // we need to know where we are and how far we come basically
        // k is only 10^4 so it is really fine
        set<pair<int, int>> visited; // for the idxs basically
        visited.insert({0, 0});
        for (int i = 0; i < k; ++i) {
            auto [total, idx1, idx2] = sum_to_idxs.top();
            sum_to_idxs.pop();
            output.push_back({nums1[idx1], nums2[idx2]});
            // we will just add the two and choose the best one on the next iteration
            // because the only best possible next options are to move it forwards by 1 in either one
            if (idx1 + 1 < nums1.size() && !visited.contains({idx1 + 1, idx2})) {
                visited.insert({idx1 + 1, idx2});
                sum_to_idxs.push({nums1[idx1 + 1] + nums2[idx2], idx1 + 1, idx2});
            }
            if (idx2 + 1 < nums2.size() && !visited.contains({idx1, idx2 + 1})) {
                visited.insert({idx1, idx2 + 1});
                sum_to_idxs.push({nums1[idx1] + nums2[idx2 + 1], idx1, idx2 + 1});
            }
        }
        return output;
    }
};