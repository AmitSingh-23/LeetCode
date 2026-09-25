class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        vector<int> even(nums.size() + 1, 0);
        vector<int> odd(nums.size() + 1, 0);
        for (int i = nums.size() - 1; i >= 0; i--) {

            if (i % 2 == 0) {
                even[i] = nums[i];
            } else {
                odd[i] = +nums[i];
            }
            even[i] += even[i + 1];
            odd[i] += odd[i + 1];
        }

        int podd = 0;
        int peven = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                if (peven + odd[i] == podd + even[i] - nums[i])
                    ans++;
                peven += nums[i];
            } else {
                if (podd + even[i] == peven + odd[i] - nums[i])
                    ans++;
                podd += nums[i];
            }
        }
        return ans;
    }
};