class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        vector<vector<int>> vt(grid.size(), vector<int>(grid[0].size(), 0));
        queue<pair<int, int>> qt;
        int result = 0;
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0;i< grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1 && vt[i][j] == 0) {
                    qt.push({i, j});
                    int sum = 1;
                    vt[i][j] = 1;
                    while (!qt.empty()) {
                        int fir = qt.front().first;
                        int sec = qt.front().second;
                        qt.pop();
                        for (int k = 0; k < 4; k++) {
                            int x = fir + dir[k][0];

                            int y = sec + dir[k][1];
                            if (x >= 0 && y >= 0 && x < grid.size() &&
                                y < grid[i].size() && grid[x][y] == 1 &&
                                vt[x][y] == 0) {
                                sum++;
                                vt[x][y] = 1;
                                qt.push({x, y});
                            }
                        }
                    }
                    result=max(result,sum);
                }
            }
        
        }
        return result;
    }
};