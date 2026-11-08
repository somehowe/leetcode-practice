class Solution {
public:
    string removeDuplicates(string str, int k) {
        stack<pair<char, int>> s; // letter and freq
        for (char c : str) {
            if (s.empty() || s.top().first != c) s.push({c, 1});
            else if (s.top().second + 1 == k) s.pop();
            else s.top().second += 1;
        }
        string res;
        while (!s.empty()) {
            auto [c, cnt] = s.top();
            s.pop();
            res.append(cnt, c);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};