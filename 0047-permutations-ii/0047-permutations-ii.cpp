class Solution {
public:
    int size;
    void backtrack(vector<vector<int>> &output, vector<int> &curr, 
                   unordered_map<int, int> &num_to_freq) {
        if (curr.size() == size) {
            output.push_back(curr);
            return;
        }
        for (auto &[num, freq] : num_to_freq) {
            // we will only try this one out once
            if (freq == 0) continue;
            --freq;
            curr.push_back(num);
            backtrack(output, curr, num_to_freq);
            curr.pop_back();
            ++freq;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        size = nums.size();
        vector<vector<int>> output;
        vector<int> curr;
        unordered_map<int, int> num_to_freq;
        for (int i : nums) {
            if (num_to_freq.contains(i)) ++num_to_freq[i];
            else num_to_freq[i] = 1;
        }
        // 11xxx, 1x1xx, 1xx1x, 1xxx1, x11xx, x1x1x, x1xx1, xx11x, xx1x1, xxx11
        backtrack(output, curr, num_to_freq);
        return output;
    }
};