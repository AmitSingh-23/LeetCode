class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        return max(check(grid, k, dp, 0, 0, 0, m, n), -1);
    }
    int check(vector<vector<int>>& grid, int& k,
              vector<vector<vector<int>>>& dp, int i, int j, int cost, int& m,
              int& n) {
        if(i>=m||j>=n){
            return INT_MIN;
        }
        if (dp[i][j][cost] != -1)
            return dp[i][j][cost];

        int temp=cost;
        if (grid[i][j] > 0) {
           cost++;
        }

        if (cost > k) {
            return INT_MIN;
        }

        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        int right = check(grid, k, dp, i + 1, j, cost, m, n);
        int down = check(grid, k, dp, i, j + 1,cost, m, n);

        int val = max(right, down);

        if (val == INT_MIN) {
            dp[i][j][temp] = INT_MIN;
        } else {
            dp[i][j][temp] = val + grid[i][j];
        }

        return dp[i][j][temp];
    }
};