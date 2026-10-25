class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        vector<int> vt(nums.size(), 0);
        long long totals = 0;
        for (int i = 0; i < nums.size(); i++) {
            string dig = to_string(nums[i]);
           sort(dig.begin(), dig.end(), greater<char>());
            totals += nums[i];
            vt[i] = stoi(dig) - nums[i];
        }
        sort(vt.begin(), vt.end(), greater<int>());
        int i = 0;
        while (i < nums.size() && k--) {
            totals += vt[i];
            i++;
        }
        return totals;
    }
};