class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                string pre = nums[i] + nums[j];
                string post = nums[j] + nums[i];
                if (pre == target) {
                    count++;
                }
                if (post == target) {
                    count++;
                }
            }
        }
        return count;
    }
};