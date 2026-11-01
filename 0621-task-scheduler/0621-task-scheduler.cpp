class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks) {
            ++freq[c - 'A'];
        }
        int max_count = *max_element(freq.begin(), freq.end());
        int num_max = count_if(freq.begin(), freq.end(), [max_count](int n){ return n == max_count; });
        return max(static_cast<int>(tasks.size()), (max_count - 1) * (n + 1) + num_max);
    }
};