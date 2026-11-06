class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        // we will go through row by row and if we find a match then 
        // we will basically add 1 to the rest of the row because we found that match
        // the outsides are all 0 good that is what we want
        // dp[i][j] is the longest we could have subsequence we could have gotten from index i - 1 and j - 1
        for (int i = 1; i <= text1.size(); ++i) {
            for (int j = 1; j <= text2.size(); ++j) {
                if (text1[i - 1] == text2[j - 1]) {
                    // what did we have before including both of them
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};