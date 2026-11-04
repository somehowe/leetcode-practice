class Solution {
public:
    bool dfs(vector<int> &nums, int idx, int target, vector<vector<int>> &memo) {
        if (target == 0) return true;
        else if (target < 0) return false;
        else if (idx == nums.size()) return false; 
        if (memo[idx][target] != -1) return memo[idx][target];
        // we could memoize with what target was there
        // try both including it and not
        if (dfs(nums, idx + 1, target - nums[idx], memo)) return memo[idx][target] = true;
        return memo[idx][target] = dfs(nums, idx + 1, target, memo);
    }
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 == 1) return false;
        int target = total / 2;
        // we need a cache to show it is possible or not, it will be what is idx at and what is target
        // then 1 is going to be for true and 0 for false
        vector<vector<int>> memo(nums.size(), vector<int>(target + 1, -1));
        return dfs(nums, 0, target, memo);
    }
};