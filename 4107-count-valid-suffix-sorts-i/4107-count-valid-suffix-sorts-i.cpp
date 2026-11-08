class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        unordered_map<int, int> num_freq_nums;
        unordered_map<int, int> num_freq_target;
        for (int i = 0; i < target.size(); ++i) {
            ++num_freq_nums[nums[i]];
            ++num_freq_target[target[i]];
        }
        if (num_freq_nums != num_freq_target) return 0;
        int stop_equal = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != target[i]) {
                stop_equal = i;
                break;
            }
        }
        int stop_dec = target.size() - 1;
        for (int j = target.size() - 1; j > 0; --j) {
            if (target[j] <= target[j - 1]) {
                stop_dec = j - 1;
            } else {
                break;
            }
        }
        if (stop_dec > stop_equal) return 0;
        return stop_equal - stop_dec + 1; // +1 for the overlap
    }
};