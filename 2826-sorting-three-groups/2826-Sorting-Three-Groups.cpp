class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int mid = 0;
        int m = nums.size();
        for (int i = 0; i < m; i++) {
            if (nums[i] == 1) {
                left++;
            } else if (nums[i] == 2) {
                mid = max(left, mid) + 1;
            } else {
                right = max(left, max(right, mid)) + 1;
            }
        }
        return m - max(mid, max(left, right));
    }
};