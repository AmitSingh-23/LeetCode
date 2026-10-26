class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int count = 0;
        vector<vector<int>> visited(rows, vector<int>(cols, 0));
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0 || visited[i][j] == 1)
                    continue;

                queue<pair<int, int>> qt;
                qt.push({i, j});
                visited[i][j] = 1;
                long long sum = 0;

                while (!qt.empty()) {
                    int r = qt.front().first;
                    int c = qt.front().second;
                    sum += grid[r][c];
                    qt.pop();

                    for (int f = 0; f < 4; f++) {
                        int x = r + dir[f][0];
                        int y = c + dir[f][1];

                        if (x >= 0 && y >= 0 && x < rows && y < cols &&
                            grid[x][y] != 0 && visited[x][y] == 0) {
                            qt.push({x, y});
                            visited[x][y] = 1;
                        }
                    }
                }
                if (sum % k == 0&&sum!=0)
                    count++;
            }
        }
        return count;
    }
};