
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int i = 0, sum = 0;
        int first = INT_MAX;
        int scnd = INT_MAX;
        int check = 0;
        int n = arr.size();

        vector<int> left(n, INT_MAX);

        for (int j = 0; j < n; j++) {
            sum += arr[j];

            while (sum > target) {
                sum -= arr[i++];
            }

            if (sum == target) {
                int len = j - i + 1;

                if (i > 0 && left[i - 1] != INT_MAX) {
                    scnd = min(scnd, len + left[i - 1]);
                }

                first = min(first, len);
            }

            left[j] = first;
        }

        return scnd == INT_MAX ? -1 : scnd;
    }
};
