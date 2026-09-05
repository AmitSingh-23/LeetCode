class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
          int n = nums.size();
        vector<int> small(n, 0);
        small[0] = nums[0];
        vector<int> big(n, 0);
        big[n - 1] = nums[n - 1];

        for (int i = 1; i < nums.size(); i++) {
            small[i] = max(small[i - 1], nums[i]);
        }
        for (int i = n - 2; i >= 0; i--) {
            big[i] = min(big[i + 1], nums[i]);
        }
        int result=-1;
        for (int i = 0; i < nums.size(); i++) {
            if(small[i] - big[i]<=k){
                result=i;
                break;
            }
        }
        return result;
    }
};