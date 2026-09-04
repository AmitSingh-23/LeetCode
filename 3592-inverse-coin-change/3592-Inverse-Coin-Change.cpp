class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> coin;
        for (int i = 0; i < numWays.size(); i++) {
            vector<vector<int>> dp(coin.size(), vector<int>(i + 2, -1));
            int ways = diffways(coin, i + 1, 0, dp);

            if (numWays[i] < ways || numWays[i] - ways > 1)
                return {};
            if (ways != numWays[i])
                coin.push_back(i + 1);
        }
        return coin;
    }
    int diffways(vector<int>& coin, int remain, int i,
                 vector<vector<int>>& dp) {
        if (remain == 0)
            return 1;
        if (i == coin.size() || remain < 0) {
            return 0;
        }
        if (dp[i][remain] != -1)
            return dp[i][remain];

        int take = diffways(coin, remain - coin[i], i, dp);
        int nottake = diffways(coin, remain, i + 1, dp);
        return dp[i][remain] = nottake + take;
    }
};