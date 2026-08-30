class Solution {
public:
int getScore(const vector<int>& arr) {
        int m = arr.size();
        if (m < 2) return 0;
        
        vector<int> pref(m);
        pref[0] = arr[0];
        for (int i = 1; i < m; i++) {
            pref[i] = std::gcd(pref[i - 1], arr[i]);
        }
        
        vector<int> suff(m);
        suff[m - 1] = arr[m - 1];
        for (int i = m - 2; i >= 0; i--) {
            suff[i] = std::gcd(suff[i + 1], arr[i]);
        }
        
        int score = 0;
        for (int i = 0; i < m - 1; i++) {
            if (pref[i] == suff[i + 1]) {
                score++;
            }
        }
        return score;
    }
    int maxValidSplits(vector<int>& nums) {
    
        int n = nums.size();
        if (n < 2) return 0;
        
        int max_score = 0;
        
        max_score = getScore(nums);
        
        for (int i = 0; i < n; i++) {
            vector<int> temp_arr;
            temp_arr.reserve(n - 1); 
            
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    temp_arr.push_back(nums[j]);
                }
            }
            
            max_score = max(max_score, getScore(temp_arr));
        }
        
        return max_score;
    
    }
};