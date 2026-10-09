class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int, int>> st;
        for (int i = 0; i < circles.size(); i++) {
            int x = circles[i][0];
            int y = circles[i][1];
            int r = circles[i][2];
            for (int i = x - r; i <= x + r; i++) {
                int j = y - r;
                while (j <= y + r) {
                    if ((x-i)*(x-i) + (y-j )*(y-j) <= r * r)
                        st.insert({i, j});
                    j++;
                }
            }
        }
        return st.size();
    }
};