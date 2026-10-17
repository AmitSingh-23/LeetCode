class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<pair<int, int>> vt(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            vt[i].first = digsum(nums[i]);
            vt[i].second = i;
        }

        int count = 0;

        vector<pair<int, int>> vt2 = vt;

        sort(vt.begin(), vt.end(),
             [&](const pair<int, int>& a, const pair<int, int>& b) {
                 if (a.first != b.first)
                     return a.first < b.first;
                 return nums[a.second] < nums[b.second];
             });

        vector<bool> visited(nums.size(), false);

        for (int i = 0; i < vt.size(); i++) {
            if (visited[i] || vt[i].second == i)
                continue;

            int cycle_size = 0;
            int j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = vt[j].second;
                cycle_size++;
            }

            count += cycle_size - 1;
        }

        return count;
    }

    int digsum(int n) {
        int sum = 0;

        while (n != 0) {
            sum += n % 10;
            n = n / 10;
        }

        return sum;
    }
};