class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> umpp;
        set<pair<int, int>> st;
        for (int i = 0; i < nums.size(); i++) {
            umpp[nums[i]]++;
        }
        for (auto& [key, value] : umpp) {
            if (k ==0) {
                if (value > 1)
                    st.insert({key, key});
            } else {
                int prev = key - k;
                int next = key + k;
                if (umpp.find(prev) != umpp.end()) {
                    st.insert({prev, key});
                    st.insert({key, prev});
                }
                if (umpp.find(next) != umpp.end()) {
                    st.insert({next, key});
                    st.insert({key, next});
                }
            }
        }
        return (k == 0) ? st.size() : st.size() / 2;
    }
};