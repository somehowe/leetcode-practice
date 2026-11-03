class Solution {
public:
    bool isPal(int l, int r, const string &s) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    void dfs(vector<vector<string>> &output, vector<string> &curr, string &s, int l, int r, int len) {
        // we still have to do the base cases where we push onto the string or return void
        if (r == s.size()) { // r is past the end so it would have filled it
            if (len == s.size()) {
                output.push_back(curr);
            } else {
                // this can't be valid so do nothing
            }
            return;
        }
        // assume we have valid indices right now:
        // we should first try making it bigger
        dfs(output, curr, s, l, r + 1, len);
        if (isPal(l, r, s)) {
            int len_sub = r - l + 1;
            // then we should both add it onto string and keep trying
            curr.push_back(s.substr(l, len_sub));
            dfs(output, curr, s, r + 1, r + 1, len + len_sub);
            curr.pop_back(); // reset to normal for others. 
        } else {
            // maybe making l bigger will make it a palindrome
            dfs(output, curr, s, l + 1, r, len);
            // we don't need two controlling going right
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> output;
        vector<string> curr;
        dfs(output, curr, s, 0, 0, 0);
        return output;
    }
};