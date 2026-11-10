class Solution {
public:
    void backtrack(int total,int idx, vector<int> &curr, vector<int>& candidate, vector<vector<int>> &output) {
        if (total == 0) {
            output.push_back(curr);
            return;
        } else if (total < 0 || idx == candidate.size()) return; // we didn't get it
        // how manyy of the same element do we even have?
        int cnt = 1;
        int curr_idx = idx;
        while (curr_idx + 1 < candidate.size() && candidate[curr_idx] == candidate[curr_idx + 1]) {
            ++curr_idx;
            ++cnt;
        }
        int og_total = total;
        for (int i = 0; i < cnt; ++i) {
            int new_index = idx + 1 + i;
            curr.push_back(candidate[idx]);
            total -= candidate[idx];
            // skip the block
            backtrack(total, idx + cnt, curr, candidate, output);
        }
        for (int i = 0; i < cnt; ++i) curr.pop_back();
        // try not including it
        backtrack(og_total, idx + cnt, curr, candidate, output);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        backtrack(target, 0, curr, candidates, output);
        return output;
    }
};