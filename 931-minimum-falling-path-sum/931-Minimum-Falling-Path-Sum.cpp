class Solution {
public:
   int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix.size();
        vector<vector<int>> vt(m, vector<int>(n, -1));
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<int>> direction = {{1, 1}, {1, -1}, {1, 0}};
        int result = INT_MAX;
        for (int i = 0; i < m; i++) {
            if (vt[0][i] == -1) {
                result = min(check(vt, direction, matrix, 0, i, m, n, dp), result);
            }
        }
        return result;
    }
    int check(vector<vector<int>>& vt, vector<vector<int>>& direction,
              vector<vector<int>>& matrix, int i, int j, int& m, int& n,
              vector<vector<int>>& dp) {
        if (i == m - 1)
            return matrix[i][j];

        if (vt[i][j] != -1)
            return dp[i][j];
        int result = INT_MAX;
        for (int k = 0; k < 3; k++) {
            int p = i + direction[k][0];
            int q = j + direction[k][1];
            if (p >= 0 && q >= 0 && q < n && p < m) {
                result = min(matrix[i][j] + check(vt, direction, matrix, p, q, m, n, dp), result);
            }
        }
        vt[i][j] = 0;
        return dp[i][j] = result;
              }

    };