class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // let's do 
        // dp[i] will represent if it is possible to get i sum
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 == 1) return false;
        int target = total / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = target - 1; j >= 0; --j) { // go down so we update it in the opposite direction
                // because before we were updating it we should do the biggest numbers first so it doesn't
                // affect it
                if (dp[j] && nums[i] + j <= target) dp[j + nums[i]] = true;
            }
        }
        return dp[target];
    }
};