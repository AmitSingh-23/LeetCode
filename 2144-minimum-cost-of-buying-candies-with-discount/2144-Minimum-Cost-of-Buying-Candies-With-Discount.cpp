class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end());
        int skip = 1;
        int result = 0;
        for (int i = cost.size() - 1; i >= 0; i--) {
            if (skip == 3) {
               
                skip = 1;
            } else {
                result += cost[i];
                skip++;
            }
        }
        return result;
    }
};