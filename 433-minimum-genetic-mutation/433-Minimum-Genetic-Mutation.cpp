class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> qt;
        qt.push(startGene);
        string target = endGene;
        vector<int> vt(bank.size(), 0);

        int result = 0;

        while (!qt.empty()) {
            int m = qt.size();
            while (m--) {
                string s = qt.front();
                qt.pop();
                if (s == target)
                    return result;

                for (int i = 0; i < bank.size(); i++) {
                    if (vt[i] == 0) {
                        int change = 0;

                        for (int j = 0; j < bank[i].length(); j++) {
                            if (s[j] != bank[i][j])
                                change++;
                        }
                        if (change == 1) {
                            qt.push(bank[i]);
                            vt[i] = -1;
                        }
                    }
                }
            }
            result++;
        }

        return -1;
    }
};