class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> output;
        int idx2 = 0;
        int idx1 = 0;
        int last1 = firstList.size();
        int last2 = secondList.size();
        while (idx1 != last1 && idx2 != last2) {
            if (firstList[idx1][1] < secondList[idx2][0]) {
                ++idx1; 
                continue;
            } else if (firstList[idx1][0] > secondList[idx2][1]) {
                ++idx2;
                continue;
            }
            output.push_back({max(firstList[idx1][0], secondList[idx2][0]), 
                              min(firstList[idx1][1], secondList[idx2][1])});
            if (firstList[idx1][1] > secondList[idx2][1]) ++idx2;
            else ++idx1;
        }
        return output;
    }
};