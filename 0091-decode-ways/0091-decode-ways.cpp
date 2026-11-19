class Solution {
public:
    int dp(string &s, int idx, vector<int> &memo) {
        static unordered_set<int> allowed_second = {'0', '1', '2', '3', '4', '5', '6'};
        if (idx == s.size()) return 1;
        if (s[idx] == '0') return 0;
        if (memo[idx] != -1) return memo[idx];
        int curr = s[idx];
        if (idx + 1 < s.size() &&
            (curr == '1' || (curr == '2' && allowed_second.contains(s[idx + 1])))) {
            return memo[idx] = dp(s, idx + 1, memo) + dp(s, idx + 2, memo);
        } else {
            // so it would be 0, 3-9, so definitely couldn't start
            return memo[idx] = dp(s, idx + 1, memo);
        }
    }
    int numDecodings(string s) {
        vector<int> memo(s.size(), -1);
        return dp(s, 0, memo);
    }
};