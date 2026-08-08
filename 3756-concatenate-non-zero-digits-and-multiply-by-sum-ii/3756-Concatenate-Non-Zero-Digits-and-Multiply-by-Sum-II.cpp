class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.length();
        long long mod = 1e9 + 7;
        vector<int> prefix(m + 1, 0);
        vector<int> count(m + 1, 0);
        vector<long long> val(m + 1, 0);
        vector<int> result(queries.size(), 0);
        vector<long long> power10(m + 1, 1);
        for (int i = 0; i < m; i++) {
            int temp = s[i] - '0';
            prefix[i + 1] = prefix[i] + temp;
            power10[i + 1] = (power10[i] * 10) % mod;
            if (temp > 0) {
                count[i + 1] = count[i] + 1;
                val[i + 1] = (val[i] * 10 + temp) % mod;
            } else {
                count[i + 1] = count[i];
                val[i + 1] = val[i];
            }
        }
        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0] + 1;
            int r = queries[i][1] + 1;
            long long sum = (prefix[r] - prefix[l - 1]);
            int k = count[r] - count[l - 1];
            long long val1 =
                ((val[r] - val[l - 1] * power10[k]) % mod + mod) % mod;
            result[i] = (sum * val1) % mod;
        }
        return result;
    }
};