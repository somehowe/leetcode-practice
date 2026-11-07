class Solution {
public:
    bool isValid(string str) {
        unordered_map<char, char> pairs = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        stack<char> s;
        for (char c : str) {
            if (pairs.contains(c)) { // contains an open one
                s.push(c);
            } else { // contains a closer
                if (s.empty() || pairs[s.top()] != c) return false;
                s.pop();
            }
        }
        return s.empty();
    }
};