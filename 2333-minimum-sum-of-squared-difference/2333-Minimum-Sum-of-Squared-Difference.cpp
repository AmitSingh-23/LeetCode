
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {

        priority_queue<pair<long long, int>> pq;
        unordered_map<int, int> umpp;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            umpp[d]++;
        }

        for (auto& [key, value] : umpp) {
            pq.push({key, value});
        }

        long long total = 1LL * k1 + k2;

        while (total > 0 && !pq.empty()) {
            long long first = pq.top().first;
            int freq = pq.top().second;
            pq.pop();

            if (first == 0)
                return 0;

            long long second = pq.empty() ? 0 : pq.top().first;
            long long cost = (first - second) * freq;

            if (total >= cost) {
                total -= cost;

                if (pq.empty())
                    return 0;

                int freq2 = pq.top().second;
                pq.pop();

                pq.push({second, freq + freq2});
            }
            else {
                long long q = total / freq;
                long long rem = total % freq;

                long long high = first - q;
                long long low = high - 1;

                long long ans = (freq - rem) * high * high
                              + rem * low * low;

                while (!pq.empty()) {
                    long long val = pq.top().first;
                    long long cnt = pq.top().second;
                    pq.pop();

                    ans += cnt * val * val;
                }

                return ans;
            }
        }

        long long ans = 0;

        while (!pq.empty()) {
            long long val = pq.top().first;
            long long cnt = pq.top().second;
            pq.pop();

            ans += cnt * val * val;
        }

        return ans;
    }
};
