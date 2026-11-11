class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int max_window = 0;
        for (int r = 0; r < nums.size(); ++r) {
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