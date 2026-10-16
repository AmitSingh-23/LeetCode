
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int result = 0;
        int n = values.size();
        int i = values[0];

        for (int j = 1; j < n; j++) {
            result = max(result, i + values[j] - j);
            i = max(i, values[j] + j);
        }

        return result;
    }
};
