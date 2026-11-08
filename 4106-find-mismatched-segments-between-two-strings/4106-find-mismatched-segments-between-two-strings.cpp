class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        string curr_s1;
        string curr_s2;
        vector<vector<string>> output;
        for (int i = 0; i < s1.size(); ++i) {
            if (s1[i] != s2[i]) {
                curr_s1.push_back(s1[i]);
                curr_s2.push_back(s2[i]);
            } else {
                // they are the same
                if (!curr_s1.empty()) {
                    output.push_back({curr_s1, curr_s2});
                    curr_s1.clear();
                    curr_s2.clear();
                }
            }
        }
        if (!curr_s1.empty()) {
            output.push_back({curr_s1, curr_s2});
        }
        return output;
    }
};