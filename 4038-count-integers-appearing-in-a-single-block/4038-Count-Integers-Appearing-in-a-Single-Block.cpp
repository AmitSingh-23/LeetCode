class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, int> umpp;
        nums.push_back(-1);
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[j] != nums[i]) {
                umpp[nums[j]]++;
                j = i;
            }
        }
        int count = 0;
        for (auto [key, value] : umpp) {
            if (value == 1)
                count++;
        }
        return count;
    }
};