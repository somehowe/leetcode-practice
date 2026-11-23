class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // have a vector of a b basically and we have a window that is the size of s2
        int n = s1.size();
        int m = s2.size();
        if (n > m) return false;
        vector<int> freq(26, 0);
        for (int i = 0; i < n; ++i) {
            ++freq[s1[i] - 'a'];
            --freq[s2[i] - 'a'];
        }
        bool all_0 = true;
        for (int j = 0; j < 26; ++j) {
            if (freq[j]) {
                all_0 = false; break;
            }
        }
        if (all_0) return true;
        for (int l = 1, r = n; r < m; ++l, ++r) {
            // update them
            ++freq[s2[l - 1] - 'a']; 
            --freq[s2[r] - 'a'];
            bool all_0 = true;
            for (int j = 0; j < 26; ++j) {
                if (freq[j]) {
                    all_0 = false; break;
                }
            }
            if (all_0) return true;
        }
        return false;
    }
};