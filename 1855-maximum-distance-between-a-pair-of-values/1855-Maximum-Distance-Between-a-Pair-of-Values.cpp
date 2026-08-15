class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {

        int result = 0;
        int n = nums2.size();
        for (int i = 0; i < nums1.size(); i++) {
            int target = nums1[i];
            int k = i;
            int j = n - 1;
            while (k <= j) {
                int mid = (k + j) / 2;

                if (nums2[mid] >= nums1[i]) {
                    result = max(result, mid - i );
                    k = mid +1;

                } else {
                    j = mid - 1;
                }
            }
        }
        return result;
    }
};