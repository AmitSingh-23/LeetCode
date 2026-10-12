class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        long long result = 0;
        int n = nums.size();

        for (int i = 0; i < nums.size(); i++) {
            if (n % (i + 1) == 0)
                result += nums[i] * nums[i];
        }
        return result;
    }
};