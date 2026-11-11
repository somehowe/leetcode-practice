class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // maybe break into two cases
        // lowkey this is just sliding window
        // window includes l to r
        // we need to get k to its right vlaue
        int l = 0; // normally we can afford this if k > 0
        if (k > 0 && nums[0] == 0) --k;
        else while (k == 0 && l < nums.size() && nums[l] == 0) ++l;
        if (l == nums.size()) return 0;
        int max_window = 1;
        for (int r = l + 1; r < nums.size(); ++r) {
            if (nums[r] == 0) {
                if (k > 0) {
                    --k;
                } else {
                    // keep decreasing the left side
                    while (l <= r && nums[l] == 1) ++l;
                    // we got to a point where nums[l] is 0
                    if (nums[l] == 0) {
                        // ++k; we would have to subtract this anyways since r is on zero right now
                        ++l;
                    }
                }
            }
            max_window = max(max_window, r - l + 1);
        }
        return max_window;
    }
};