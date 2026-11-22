class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            ++freq[c - 'a'];
        }
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; ++i) {
            if (freq[i]) pq.push({freq[i], i + 'a'});
        }
        string output;
        while (pq.size() >= 2) {
            auto [cnt1, c1] = pq.top(); pq.pop();
            auto [cnt2, c2] = pq.top(); pq.pop();
            output += c1; output += c2;
            --cnt1; --cnt2;
            if (cnt1 > 0) pq.push({cnt1, c1});
            if (cnt2 > 0) pq.push({cnt2, c2});
        }
        // now we have one element left
        if (pq.size() == 1) {
            auto [cnt, c] = pq.top();
            if (cnt > 1 || ((output.size() >= 2) && c == output[s.size() - 2])) return "";
            else output += c;
        }
        return output; 
    }
};