class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long result = 0;
        long long size = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!(nums[i] <= maxK && nums[i] >= minK)) {
                result += (size * (size + 1)) / 2;
                size = 0;
            } else {
                size++;
            }
        }
                result += (size * (size + 1)) / 2;

        return result;
    }
};