class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        // if the others ones behind don't match then obviously can't
        // two conditions we need for index to be valid, rest have to be
        // in decreasing order that index and onwards
        // and all the other indexes need to match, they need to have the
        // the same number of each elements
        unordered_map<int, int> num_freq_nums;
        unordered_map<int, int> num_freq_target;
        for (int i = 0; i < target.size(); ++i) {
            if (num_freq_nums.contains(nums[i])) ++num_freq_nums[nums[i]];
            else num_freq_nums[nums[i]] = 1;
            if (num_freq_target.contains(target[i])) ++num_freq_target[target[i]];
            else num_freq_target[target[i]] = 1;
        }
        for (auto [num, freq] : num_freq_nums) {
            if (num_freq_target[num] != freq) return 0;
        }
        // so now we are guaranteed they have same elements
        // we need to see when they stop being equal
        int stop_equal = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != target[i]) {
                stop_equal = i;
                break;
            }
        }
        // our count can be at most stop_equal
        // now let's check when does the target stop decreasing
        int stop_dec = target.size() - 1;
        for (int j = target.size() - 1; j > 0; --j) {
            if (target[j] <= target[j - 1]) {
                // we can keep going we want this
                stop_dec = j - 1;
            } else {
                // not equal so we break
                break;
            }
        }
        // we can only have it be stop_dec and onwards
        if (stop_dec > stop_equal) return 0;
        return stop_equal - stop_dec + 1; // +1 for the overlap
    }
};