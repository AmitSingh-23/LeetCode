class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> child(k, 0);
        int result = INT_MAX;
        dfscookies(cookies, child, result, 0);
        return result;
    }
    void dfscookies(vector<int>& cookies, vector<int>& child, int& result,
                    int i) {
        if (i == cookies.size()) {
            int val = 0;
            for (int k = 0; k < child.size(); k++) {
                val = max(val, child[k]);
            }
            result = min(result, val);
            return;
        }

        for (int j = 0; j < child.size(); j++) {
            child[j] += cookies[i];
            dfscookies(cookies, child, result, i + 1);
            child[j] -= cookies[i];
        }
    }
};