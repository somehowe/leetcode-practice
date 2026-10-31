class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2; // round it down
            if (nums[right] < nums[mid]) {
                // it must be in this interval
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};