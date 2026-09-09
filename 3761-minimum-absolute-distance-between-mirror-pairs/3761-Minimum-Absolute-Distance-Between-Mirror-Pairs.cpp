class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> umpp;
        for (int i = 0; i < nums.size(); i++) {
            umpp[nums[i]].push_back(i);
        }
        int result = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int value = nums[i];
            int rev = reverse(value);

            if (umpp.find(rev) != umpp.end()) {

                auto it = upper_bound(umpp[rev].begin(), umpp[rev].end(), i);

                if (it != umpp[rev].end()) {
                    result = min(result, abs(*it - i));
                }
            }
        }

        if (result != INT_MAX)
            return result;
        return -1;
    }

    int reverse(int x) {
        int ans = 0;
        while (x != 0) {
            int rem = x % 10;
            x /= 10;

            ans = ans * 10 + rem;
        }
        return ans;
    }
};