class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        vector<int> temp;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                temp.push_back(grid[i][j]);
            }
        }
        sort(temp.begin(), temp.end());
        
        int index = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                grid[i][j] = temp[index++];
            }
        }

        int val = grid.size() * grid[0].size();
        int mid1 = 0;
        int mid2 = 0;

        if (val % 2 == 0) {
            mid1 = val / 2;
            mid2 = val / 2 + 1;
        } else {
            mid1 = val / 2 + 1;
            mid2 = val / 2 + 1;
        }
        
        int cols = grid[0].size();
        mid1 = grid[(mid1 - 1) / cols][(mid1 - 1) % cols];
        mid2 = grid[(mid2 - 1) / cols][(mid2 - 1) % cols];

        int operations = 0;
        bool possible = true;
        int remain = grid[0][0] % x;
        
        for (int i = 0; i < grid.size() && possible; i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (remain != grid[i][j] % x) {
                    possible = false;
                }
                operations += abs(grid[i][j] - mid1) / x;
            }
        }
        
        return (possible) ? operations : -1;
    }
};