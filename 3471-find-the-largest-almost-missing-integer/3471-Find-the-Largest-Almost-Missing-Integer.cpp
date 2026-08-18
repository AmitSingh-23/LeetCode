class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> umpp;
        int result = -1;
        int val = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            umpp[nums[i]]++;
            val = max(val, nums[i]);
        }

        if (k == 1) {
            for (auto [key, value] : umpp) {
                if (value == 1) {
                    result = max(key, result);
                }
            }
        } else {
            if (k == nums.size()) {
                result = val;
            } else if (umpp[nums[nums.size() - 1]] == 1) {
                result = max(nums[nums.size() - 1], result);
            }
            if (umpp[nums[0]] == 1) {
                result = max(nums[0], result);
            }
        }
        return result;
    }
};