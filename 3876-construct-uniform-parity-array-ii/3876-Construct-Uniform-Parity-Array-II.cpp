class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool oddp = false;
        int small = INT_MAX;
        for (int i = 0; i < nums1.size(); i++) {
            if (nums1[i] % 2 != 0)
                oddp = true;
            small = min(small, nums1[i]);
        }
        if (oddp) {
            if (small % 2 == 0)
                return false;
        }
        return true;
    }
};