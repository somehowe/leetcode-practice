class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
       int total = accumulate(weights.begin(), weights.end(), 0);
       // the best that we can possibly do is total / days
       // total
       // we have to do it in the order thye give.  
       int l = (total + days - 1) / days;
       int r = total; // maybe just one and it is massive
       while (l < r) {
          int mid = l + (r - l) / 2;
          int idx = 0;
          for (int i = 0; i < days && idx < weights.size(); ++i) {
            // we can go through and add up to mid
            int curr = 0;
            while (idx < weights.size() && weights[idx] + curr <= mid) {
                curr += weights[idx];
                ++idx;
            }
          }
          if (idx == weights.size()) {
            // we got to the end
            r = mid;
          } else {
            // we did not get to the end so this definitely does not work
            l = mid + 1; // have to give a bigger target
          }
       }
       return l;
    }
};