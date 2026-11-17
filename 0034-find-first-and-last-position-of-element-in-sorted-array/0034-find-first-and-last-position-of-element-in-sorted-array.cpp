class Solution {
public:
    int b_search(vector<int>& nums, int l, int r, int target, bool right_side) {
        while (l <= r) {
            int mid = l + (r - l + (right_side ? 1 : 0)) / 2;
            if (nums[mid] == target && l == r) {
                return l;
            } else if (nums[mid] == target) {
                if (right_side) {
                    l = mid; // we can skip the ones to our left
                } else {
                    r = mid;
                }
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1; // should never happen if we are using this right
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[l] == target && nums[r] == target) {
                return {l, r};
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else {
                // now we know that the midpoint is where target is be our endpoints
                // is where it is not. I mean all we know is at least one endpoint is not
                // potentialy we just binary search on these and we find their value
                return {b_search(nums, l, mid, target, false), b_search(nums, mid, r, target, true)};
            }
        }
        return {-1, -1};
    }
};