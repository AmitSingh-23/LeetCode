class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n, 0));
        unordered_map<char, pair<int, int>> umpp;
        umpp['U'] = {-1, 0};
        umpp['L'] = {0, -1};
        umpp['D'] = {1, 0};
        umpp['R'] = {0, 1};

        int r = 0;
        int c = 0;
        visited[r][c] = 1;

        while (1) {

            int f = r + umpp[grid[r][c]].first;
            int g =c + umpp[grid[r][c]].second;
             if (f >= m || f < 0 || g >= n || g < 0 ||
        visited[f][g] == 1) {
        return {r, c};
    }
            r = f;
            c = g;
            visited[r][c] = 1;
        }

        return {r, c};
    }
};