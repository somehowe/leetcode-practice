class Solution {
public:
    bool isPal(int l, int r, const string &s) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }
    // curr contains only palindromes and conctaing them gives exactly 
    // everything behind start, and everything from start onward still need to be partitioned
    void dfs(vector<vector<string>> &output, const string &s, vector<string> &curr, int start) {
        // start is the start of the first word we haven't seen yet
        if (start == s.size()) {
            output.push_back(curr); // as we know it will be valid since we check as we push on
            return;
        }
        // every recursive step preserves the invariant
        for (int end = start; end < s.size(); ++end) {
            if (!isPal(start, end, s)) continue;
            curr.push_back(s.substr(start, end - start + 1));
            dfs(output, s, curr, end + 1);
            curr.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> output;
        vector<string> curr;
        dfs(output, s, curr, 0);
        return output;
    }
};