class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long  sum = 0;
        int result = 0;
        int lt = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            lt = min(nums[i], lt);
            sum += nums[i];
        }
        result = sum - (nums.size() * lt);
        return result;
    }
};