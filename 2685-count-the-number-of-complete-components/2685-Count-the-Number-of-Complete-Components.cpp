class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> visited1(n, -1);
        vector<int> visited2(n, -1);

        int count = 0;

        for (int i = 0; i < n; i++) {

            if (visited1[i] == -1) {

                int num = dfs2(adj, visited1, i);

                bool result = true;

                dfs(result, num - 1, adj, visited2, i);

                if (result == true)
                    count++;
            }
        }

        return count;
    }

    bool dfs(bool& result, int num, vector<vector<int>>& adj,
             vector<int>& visited, int i) {

        visited[i] = 0;

        if (adj[i].size() != num) {
            return result = false;
        }

        for (int j = 0; j < adj[i].size(); j++) {

            int neighbor = adj[i][j];

            if (visited[neighbor] == -1) {
                dfs(result, num, adj, visited, neighbor);
            }
        }

        return result;
    }

    int dfs2(vector<vector<int>>& adj, vector<int>& visited, int i) {

        visited[i] = 0;

        int count = 1;

        for (int j = 0; j < adj[i].size(); j++) {

            int neighbor = adj[i][j];

            if (visited[neighbor] == -1) {
                count += dfs2(adj, visited, neighbor);
            }
        }

        return count;
    }
};