class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int j = 0;

        int m = nums.size();
        int sum = 0;
        for (int i = 0; i < m; i++) {
            sum += nums[i];
        }
        if(sum==x)return m;
        else if(sum<x)return -1;
        int i = 0;
        int sum2 = 0;
        int result = -1;
        while (j < m) {
            sum2 += nums[j];

            while (i <= j && sum - sum2 <= x) {
                if (sum - sum2 == x) {
                    result = max((j - i + 1), result);
                }
                sum2 -= nums[i];
                i++;
            }
            j++;
        }
        return (result == -1) ? result : m - result;
    }
};