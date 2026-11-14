class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_prof = 0;
        int curr_lo = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (max_prof < prices[i] - curr_lo) max_prof = prices[i] - curr_lo;
            else if (curr_lo > prices[i]) curr_lo = prices[i];
        }
        return max_prof;
    }
};