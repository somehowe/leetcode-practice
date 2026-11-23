class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        array<int, 26> freq;
        array<int, 26> window;
        for (int i = 0; i < s1.size(); ++i) {
            ++freq[s1[i] - 'a'];
            ++window[s2[i] - 'a'];
        }
        if (freq == window) return true;
        for (int r = s1.size(); r < s2.size(); ++r) {
            --window[s2[r - s1.size()] - 'a'];
            ++window[s2[r] - 'a'];
            if (window == freq) return true;
        }
        return false;
    }
};