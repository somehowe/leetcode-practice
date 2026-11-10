class Solution {
public:
    void backtrack(int total,int idx, vector<int> &curr, vector<int>& candidate, vector<vector<int>> &output) {
        // every iteration we will choose one element (shouldn't try the same element twice that woudln't )
        // make sense
        if (total == 0) {
            output.push_back(curr);
            return;
        }
        for (int i = idx; i < candidate.size(); ++i) {
            // choose what we want the next element to be
            if (i > idx && candidate[i] == candidate[i - 1]) continue; // wouldn't make sense to choose a duplicate
            if (candidate[i] > total) break;
            curr.push_back(candidate[i]);
            backtrack(total - candidate[i], i + 1, curr, candidate, output);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtrack(target, 0, curr, candidates, output);
        return output;
    }
};