class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), INT_MAX);
        return check(dp, days, costs, 0, 1);
    }
    int check(vector<int>& dp, vector<int>& days, vector<int>& costs, int i,
              int target) {

        while (i < days.size()) {
            if (days[i] >= target)
                break;
            i++;
        }
        if (i == days.size()) {
            return 0;
        }
        if (dp[i] != INT_MAX)
            return dp[i];
        int one = costs[0] + check(dp, days, costs, i, days[i] + 1);

        int seven = costs[1] + check(dp, days, costs, i, days[i] + 7);
        int thirty = costs[2] + check(dp, days, costs, i, days[i] + 30);
        return dp[i] = min(one, min(seven, thirty));
    }
};