class Solution {
public:
    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        vector<int> vt(n, -1);
        vector<int> result;
        vector<int> second(n, 0);

        for (int i = 0; i < invocations.size(); i++) {
            adj[invocations[i][0]].push_back(invocations[i][1]);
        }
        dfs(adj, vt, k);
        bool check = true;
        for (int i = 0; i < n; i++) {
            if (vt[i] != 0) {

                for (int f = 0; f < adj[i].size(); f++) {
                    if (vt[adj[i][f]] == 0) {
                        check = false;
                    }
                }
            }
            second[i] = i;
        }
        if (!check)
            return second;
        else {
            for (int i = 0; i < vt.size(); i++) {
                if (vt[i] != 0)
                    result.push_back(i);
            }
        }
        return result;
    }
    void dfs(vector<vector<int>>& adj, vector<int>& vt, int k) {
        vt[k] = 0;
        for (int i = 0; i < adj[k].size(); i++) {
            if (vt[adj[k][i]] == -1) {
                dfs(adj, vt, adj[k][i]);
            }
        }
    }
};