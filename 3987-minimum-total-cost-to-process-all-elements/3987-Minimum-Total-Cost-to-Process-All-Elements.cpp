class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long result = 0;
        long long current = k;
        long long cost = 0;
        int borrow = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= current) {
                current -= nums[i];
                continue;
            } else {
                long long val = (nums[i] - current + k) / k;
                if ((nums[i] - current) % k == 0)
                    borrow = 1;
                cost += val - borrow;
                current = current + k * (val-borrow )- nums[i];
                borrow = 0;
            }
        }
        int mod = 1e9 + 7;
        cost=cost%mod;
        long long sum = (long long)cost * (cost + 1) / 2;
        sum = sum % mod;
        return sum;
    }
};