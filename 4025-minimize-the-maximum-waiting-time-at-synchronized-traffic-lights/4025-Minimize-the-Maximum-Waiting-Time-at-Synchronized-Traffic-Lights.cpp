class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int result = 0;
        int andha = 0;
        for (int i = 0; i < lights.size(); i++) {
            andha = max(lights[i], andha);
        }
        for (int i = 0; i < arrivalTime.size(); i++) {
            int incoming = arrivalTime[i] % period;
            if (andha <= incoming) {
                result = max(period - incoming, result);
            }
        }
        return result;
    }
};