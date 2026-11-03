class Solution {
public:
    int minMoves(vector<int>& nums) {
        int val = 0;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            val = max(val, nums[i]);
            sum += nums[i];
        }
        return val * nums.size() - sum;
    }
};