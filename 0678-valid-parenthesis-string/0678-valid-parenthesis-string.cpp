class Solution {
public:
    bool checkValidString(string s) {
        int l = 0; // the lowest number of opening brackets
        int r = 0; // highest number of opening brackets
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                ++l;
                ++r;
            } else if (s[i] == ')') {
                --l;
                --r;
            } else { // it is a *
                --l;
                ++r;
            }
            if (r < 0) return false;
            l = max(0, l);
        }
        return l <= 0 && 0 <= r;
    }
};