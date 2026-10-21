class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;
         
        for (int i = 0; i < n; i++) {
            total += nums[i];
        }
        
        long long curr = 0;
        long long half = n / 2;

        for (int i = 0; i < half; i++) {
            curr += nums[i];
        }
        
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            if (curr > total - curr) {
                result++;
            }
            
            curr -= nums[i];
            curr += nums[(i + half) % n];
        }
        
        return result;
    }
};