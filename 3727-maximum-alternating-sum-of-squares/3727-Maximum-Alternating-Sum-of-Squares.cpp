class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> vt(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
          vt[i] = 1LL * nums[i] * nums[i];
        }
        sort(vt.begin(), vt.end());
        int i = 0;
        int j = nums.size() - 1;
        long long result = 0;

        while (i <= j) {
            result += vt[j];
            j--;
            if (i <= j) {
                result -= vt[i];
                i++;
            }
        }
        return result;
    }
};