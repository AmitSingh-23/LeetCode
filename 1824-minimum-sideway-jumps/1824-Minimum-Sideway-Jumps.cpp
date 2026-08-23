class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> vt(n, vector<int>(3, 0));
        vector<vector<int>> dp(n, vector<int>(3, -1));

        for (int i = 0; i < n; i++) {
            if (obstacles[i] == 0)
                continue;
            vt[i][obstacles[i] - 1] = -1;
        }
        return check(vt, 0, 1, dp);
    }
    int check(vector<vector<int>>& vt, int i, int j, vector<vector<int>>& dp) {
        if (i == vt.size() - 1)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];

        if (vt[i + 1][j] != -1) {
            return dp[i][j] = check(vt,i+1,j,dp);

        } else {
            int val = 1e9;
            for (int k = 0; k < 3; k++) {
                if (vt[i][k] != -1 && k != j) {
                    val = min(1 + check(vt,i,k,dp),val);
                }
            }
            return dp[i][j] = val;
        }
    }
};