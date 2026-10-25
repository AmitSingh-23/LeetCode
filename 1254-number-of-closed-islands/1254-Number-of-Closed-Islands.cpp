class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> vt(rows + 2, vector<int>(cols + 2, 0));
        vector<vector<int>> visited = vt;
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                vt[i + 1][j + 1] = grid[i][j];
            }
        }
        int result = 0;
        for (int i = 0; i < vt.size(); i++) {
            for (int j = 0; j < vt[0].size(); j++) {
                if (visited[i][j] == 1)
                    continue;

                if (vt[i][j] == 0) {
                    result++;

                    visited[i][j] = 1;

                    queue<pair<int, int>> qt;
                    qt.push({i, j});
                    while (!qt.empty()) {
                        int r = qt.front().first;
                        int c = qt.front().second;
                        qt.pop();
                        for (int f = 0; f < dir.size(); f++) {
                            int x = r + dir[f][0];
                            int y = c + dir[f][1];
                            if (x >= 0 && y >= 0 && x < vt.size() &&
                                y < vt[0].size() &&
                                vt[x][y] == 0 & visited[x][y] == 0) {
                                qt.push({x, y});
                                visited[x][y] = 1;
                            }
                        }
                    }
                }
            }
        }
        return result-1;
    }
};