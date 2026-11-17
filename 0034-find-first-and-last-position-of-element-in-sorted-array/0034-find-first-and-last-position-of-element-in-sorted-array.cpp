class Solution {
public:
    int find_boundary(vector<int> &nums, int target, bool is_right) {
        int answer = -1;
        int l = 0;
        int r = static_cast<int>(nums.size()) - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            } else { // they are equal
                // take as our answer
                answer = mid;
                // but let's also see if we can get better 
                if (is_right) l = mid + 1; // can we find one further right
                else r = mid - 1;
            }
        }
        return answer;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        // we will find left and the right where they start
        return {find_boundary(nums, target, false), find_boundary(nums, target, true)};
    }
};