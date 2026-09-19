class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int result = 0;
        for (int i = 0; i < colors.size() - 1; i++) {
            if (colors[i] == colors[i + 1]) {
                int time = neededTime[i];
                int sum = neededTime[i];
                while (colors[i] == colors[i + 1]) {
                    time = max(neededTime[i+1], time);
                    sum += neededTime[i+1];
                    i++;
                }
                result += sum - time;
            }
        }
        return result;
    }
};