class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umpp;
        umpp[0] = -1;

        long long sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            int rem = sum % k;

            if (umpp.count(rem)) {
                if (i - umpp[rem] >= 2)
                    return true;
            }
            else {
                umpp[rem] = i;
            }
        }

        return false;
    }
};