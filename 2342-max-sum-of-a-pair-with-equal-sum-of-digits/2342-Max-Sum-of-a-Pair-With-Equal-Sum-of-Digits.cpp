class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> umpp;
        for (int i = 0; i < nums.size(); i++) {
            int digit = dig(nums[i]);
            umpp[digit].push_back(nums[i]);
        }
        int result = -1;
        for (auto& [key, value] : umpp) {
            if (value.size() < 2)
                continue;
            sort(value.begin(), value.end());
            int n = value.size();
            result = max(result, value[n - 1] + value[n - 2]);
        }
        return result;
    }
    int dig(int n) {
        int sum = 0;
        while (n != 0) {
            sum += n % 10;
            n = n / 10;
        }
        return sum;
    }
};