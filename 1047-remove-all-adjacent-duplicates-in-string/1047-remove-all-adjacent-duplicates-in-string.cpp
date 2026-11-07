class Solution {
public:
    string removeDuplicates(string str) {
        string res;
        for (char c : str) {
            if (res.empty() || res.back() != c) res.push_back(c);
            else res.pop_back();
        }
        return res;
    }
};