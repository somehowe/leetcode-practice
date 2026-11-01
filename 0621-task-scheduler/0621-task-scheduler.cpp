class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);
        for (char c : tasks) {
            ++freq[c - 'A'];
        }
        int max_count = *max_element(freq.begin(), freq.end());
        int num_max = count_if(freq.begin(), freq.end(), [max_count](int n){ return n == max_count; });
        int interval_len = max(n + 1, num_max);
        int num_intervals = max_count - 1;
        int other_count = tasks.size() - (max_count * num_max); // these are the ones that we still need to place
        int count = interval_len * num_intervals + num_max; 
        other_count -= num_intervals * (interval_len - num_max); // for what is leftover
        count += other_count < 0 ? 0 : other_count;
        return count;
    }
};