class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n = tokens.size();
        int i = 0;
        int j = n - 1;
        int result = 0;
        int val = 0;
        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i];
                result++;
                val = max(result, val);
                i++;
            } else if (result > 0 && i < j) {
                power += tokens[j];
                j--;
                result--;
            } else
                break;
        }
        return val;
    }
};