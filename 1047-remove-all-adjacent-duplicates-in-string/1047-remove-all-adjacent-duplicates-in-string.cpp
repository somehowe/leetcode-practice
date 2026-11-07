class Solution {
public:
    string removeDuplicates(string &s) {
        // my solution is n^2 I think.
        bool found_dup = false;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                found_dup = true;
                s.erase(s.begin() + i - 1, s.begin() + i + 1);
                break;
            }
        }
        if (found_dup) {
            return removeDuplicates(s);
        }
        return s;
    }
};