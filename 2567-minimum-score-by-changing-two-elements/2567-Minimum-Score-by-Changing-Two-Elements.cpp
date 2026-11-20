class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int m1 = INT_MIN, m2 = INT_MIN, m3 = INT_MIN;
        int mn1 = INT_MAX, mn2 = INT_MAX, mn3 = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];

            if (x >= m1) {
                m3 = m2;
                m2 = m1;
                m1 = x;
            } else if (x >= m2) {
                m3 = m2;
                m2 = x;
            } else if (x > m3) {
                m3 = x;
            }

            if (x <= mn1) {
                mn3 = mn2;
                mn2 = mn1;
                mn1 = x;
            } else if (x <= mn2) {
                mn3 = mn2;
                mn2 = x;
            } else if (x < mn3) {
                mn3 = x;
            }
        }

        return min({m1 - mn3, m3 - mn1, m2 - mn2});
    }
};