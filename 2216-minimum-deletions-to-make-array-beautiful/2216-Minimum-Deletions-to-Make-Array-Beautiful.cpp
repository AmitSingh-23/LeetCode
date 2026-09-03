class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        st.push(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            if ((st.size() - 1 )% 2 == 0 && st.top() == nums[i]) {
                continue;
            } 
                st.push(nums[i]);
            
        }
      
        if (st.size() % 2 == 0)
            return n - st.size();
        else {
            return n - st.size() + 1;
        }
    }
};