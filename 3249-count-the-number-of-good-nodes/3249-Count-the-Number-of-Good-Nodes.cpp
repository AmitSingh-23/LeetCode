class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size()+1;
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n, 0);
        int count = 0;
        dfs(count, 0, adj, visited,0);
        return count;
    }

 int dfs(int& count, int mover, vector<vector<int>>& adj, vector<int>& visited,
          int num) {
    visited[mover] = -1;

 int  change=0;
 int dis=-1;
    for (int i = 0; i < adj[mover].size(); i++) {
        if (visited[adj[mover][i]] == 0) {
            int val = dfs(count, adj[mover][i], adj, visited, 0);
            if(dis!=val){
change++;
dis=val;
            }
            num += val;
        }
    }
    if (change ==1||change==0)
        count++;
    return num + 1;
}
};