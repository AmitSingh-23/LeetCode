class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {

        unordered_map<int, int> umpp;
        int i = 0;
        int j = 0;
        int result = 0;
        int m = nums.size();
        while (j < m) {
            umpp[nums[j]]++;
            while (i < j && umpp[nums[j]] > k) {
                umpp[nums[i]]--;
                i++;
            }
            result = max(result, j - i + 1);
            j++;
        }
        return result;
    }
};