class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> vt(n);

        for (int i = 0; i < nums.size(); i++) {
            if (parent[i] == -1)
                continue;
            vt[parent[i]].push_back(i);
        }
        queue<int > qt;
        int mod=1e9+7;
        qt.push(0);
        int d = 1;
        long long sum = 0;
        long long add = 0;
        while (!qt.empty()) {
            int k = qt.size();

            for (int i = 0; i < k; i++) {
                int val = qt.front();
                add += nums[val];
                sum += (long long)nums[val] * (-d + 1);
                for (int j = 0; j < vt[val].size(); j++) {
                    qt.push(vt[val][j]);
                }
                qt.pop();
            }
            d++;
        }
        
        sum += (d - 1) * add;
        return sum;
    }
};