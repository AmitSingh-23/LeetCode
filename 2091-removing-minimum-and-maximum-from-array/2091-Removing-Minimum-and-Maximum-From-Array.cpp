class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        for (int k = 0; k < nums.size(); k++) {
            if (nums[i] > nums[k]) {
                i = k;
            }
            if (nums[j] < nums[k]) {
                j = k;
            }
        }
        int result = INT_MAX;
        result = min(min(i, j) + 1 + n - max(j, i), result);
        result = min(max(i, j) + 1, result);
        result = min(n - min(i, j) , result);
        return result;
    }
};