class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> vt1 = {nums[0]};
        vector<int> vt2 = {nums[1]};
        int k = 1;
        int j = 1;

        for (int i = 2; i < n; i++) {
            int k = vt1.size();
            int j = vt2.size();

            if (vt1[k-1] > vt2[j-1]) {
                vt1.push_back(nums[i]);

            } else {
                vt2.push_back(nums[i]);
            }
        }
        vt1.insert(vt1.end(), vt2.begin(), vt2.end());
        return vt1;
    }
};