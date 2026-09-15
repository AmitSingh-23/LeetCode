class Solution {
public:
    int minElement(vector<int>& nums) {
        int result = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            result = min(check(nums[i]), result);
        }
        return result;
    }
    int check(int n) {
        int l = 0;
        while (n != 0) {
            l += n % 10;
            n = n / 10;
        }
        return l;
    }
};