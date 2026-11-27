class Solution {
public:
    bool dp(string &str, int idx, int cnt_open, vector<vector<bool>> &memo) {
        int og_cnt = cnt_open;
        if (idx == str.size()) return cnt_open == 0;
        if (!memo[idx][cnt_open]) return false; // because if true we are done
        // the idea is if the ucrrent one is * we will try all 3 possibilities
        if (str[idx] == '(') {
            ++cnt_open;
        } else if (str[idx] == ')') {
            --cnt_open;
            if (cnt_open < 0) return false; // not feasible path
        } else {
            // it is a star
            if (dp(str, idx + 1, cnt_open + 1, memo)) return true;
            if (cnt_open >= 1 && dp(str, idx + 1, cnt_open - 1, memo)) return true;
        }
        return memo[idx][og_cnt] = dp(str, idx + 1, cnt_open, memo);
    }
    bool checkValidString(string str) {
        int cnt_open = 0;
        int n = str.size();
        // we can memoize on idx and how cnt_open is
        vector<vector<bool>> memo(n + 1, vector<bool>(n + 1, true));
        return dp(str, 0, cnt_open, memo);
    }
};
