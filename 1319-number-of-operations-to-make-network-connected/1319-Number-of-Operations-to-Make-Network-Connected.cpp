class Solution {
    vector<int> parent;
    vector<int> rank;

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        if (m < n - 1)
            return -1;
        parent.resize(n, 0);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < connections.size(); i++) {
            int r1 = findup(connections[i][0]);
            int r2 = findup(connections[i][1]);
            if (rank[r1] > rank[r2]) {
                parent[r2] = r1;
            } else if (rank[r2] > rank[r1]) {
                parent[r1] = r2;
            } else {
                parent[r2] = r1;
                rank[r1]++;
            }
        }
        unordered_set<int> st;
        for (int i = 0; i < n; i++) {
            st.insert(findup(i));
        }
        return st.size() - 1;
    }
    int findup(int n) {
        if (parent[n] == n)
            return n;
        return parent[n] = findup(parent[n]);
    };
};