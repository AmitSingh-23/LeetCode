class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower,
                                               int upper) {
        vector<int> vt(upper - lower + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= lower && nums[i] <= upper) {
                vt[nums[i] - lower] = -1;
            }
        }
        vector<vector<int>> result;
        int i = 0;
        int j = 0;

        while (j < vt.size()) {
            if (vt[j] == 0) {
                i = j;
                while (i < vt.size() && vt[i] == 0) {
                    i++;
                }
                result.push_back({j + lower, i - 1 + lower});
                j = i;
            }
            j++;
        }
        return result;
    }
};