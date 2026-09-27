class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }

        vector<vector<int>> dp(n, vector<int>(n, 2));
        int ans = 0;

        for (int j = 0; j < n; j++) {
            for (int i = j + 1; i < n; i++) {
                int need = arr[i] - arr[j];

                if (mp.count(need)) {
                    int k = mp[need];

                    if (k < j) {
                        dp[j][i] = dp[k][j] + 1;
                        ans = max(ans, dp[j][i]);
                    }
                }
            }
        }

        return ans >= 3 ? ans : 0;
    }
};