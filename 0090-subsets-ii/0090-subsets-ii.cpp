class Solution {
public:
    // we have the assumption that right now all are unique
    void subset(vector<vector<int>> &output, vector<int> &nums, int idx) {
        if (nums.size() == idx) return;
        // the trick is that we will go through all the possible number of nums[idx] 
        // in this level
        int count = 1;
        while (idx + 1 < nums.size() && nums[idx + 1] == nums[idx]) {
            ++idx;
            ++count;
        }
        // now we are on the last element that has that number and we know the count
        int level_size = output.size();
        for (int j = 0; j < level_size; ++j) {
            vector<int> curr = output[j];
            for (int i = 0; i < count; ++i) {
                curr.push_back(nums[idx]);
                output.push_back(curr);
            }
        }
        subset(output, nums, idx + 1); // move on to the next one
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // we either include it or we don't include it
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());
        output.push_back({});
        subset(output, nums, 0);
        return output;
    }
};