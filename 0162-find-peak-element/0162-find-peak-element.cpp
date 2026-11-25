class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1 || nums[0] > nums[1]) return 0;
        if (nums.size() == 2) return (nums[0] > nums[1]) ? 0 : 1;
        int r = nums.size() - 1;
        if (nums[r] > nums[r - 1]) return r;
        int l = 0;
        // invariant is that l and r never work
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            if (nums[mid] > nums[l] && nums[mid + 1] > nums[mid]) {
                // potentially it could be like 1 2 3 5 4 we are at 3 
                l = mid;
            } else if (nums[mid] > nums[r]) {
                // there's got to be something better 
                r = mid;
            } else {
                // nums[mid] is smaller than both of them
                l = mid; // there will be a peak on either side
            }
        }
        return -1; // not possible
    }
};