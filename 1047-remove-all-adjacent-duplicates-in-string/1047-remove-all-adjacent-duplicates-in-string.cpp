class Solution {
public:
    string removeDuplicates(string str) {
        stack<char> s;
        for (char c : str) {
            if (s.empty() || s.top() != c) s.push(c);
            else s.pop();
        }
        string res;
        while (!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};