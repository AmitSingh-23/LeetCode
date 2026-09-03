class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<long long>> vt(a.size(),
                                     vector<long long>(b.size(), -1e11));
        return check(a, b, vt, 0, 0);
    }
    long long check(vector<int>& a, vector<int>& b,
                    vector<vector<long long>>& vt, int i, int j) {
        if (i == a.size())
            return 0;
        else if (j == b.size())
            return -1e11;
        if (vt[i][j] != -1e11)
            return vt[i][j];
        long long take = (long long )a[i]* b[j] + check(a, b, vt, i + 1, j + 1);

        long long notake = check(a, b, vt, i, j + 1);
        return vt[i][j] = max(take, notake);
    }
};