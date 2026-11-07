class Solution {
public:
    bool isValid(string str) {
        unordered_map<char, char> pairs = {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        stack<int> s;
        for (int i = 0; i < str.size(); ++i) {
            if (pairs.contains(str[i])) { // contains an open one
                s.push(str[i]);
            } else { // contains a closer
                if (s.empty() || pairs[s.top()] != str[i]) return false;
                s.pop();
            }
        }
        return s.empty();
    }
};