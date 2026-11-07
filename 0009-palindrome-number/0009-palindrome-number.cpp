class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int order = 1;
        while (order <= x / 10) order *= 10;
        int y = x;
        while (y && x) {
            int left = x / order;
            int right = y % 10;
            if (left != right) return false;
            y /= 10;
            x %= order;
            order /= 10;
        }
        return true;
    }
};