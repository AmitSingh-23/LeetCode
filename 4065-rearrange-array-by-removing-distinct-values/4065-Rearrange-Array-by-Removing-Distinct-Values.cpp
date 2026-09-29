class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        map<int, int> umpp;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            umpp[nums[i]]++;
            count++;
        }
        vector<int> result;
        while (count) {
            for (auto& [key, value] : umpp) {
                if (value == 0)
                    continue;
                result.push_back(key);
                value--;
                count--;
            }
        }
        return result;
    }
};