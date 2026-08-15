class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<int, int> umpp;
        unordered_map<int, int> umpp2;
        int count = 0;
        int count2 = 0;
        for (int i = 0; i < secret.length(); i++) {
            if (secret[i] == guess[i]) {
                count++;
                continue;
            }
            umpp[secret[i]]++;
            umpp2[guess[i]]++;
        }
        for (auto [key, value] : umpp) {
            count2 += min(umpp[key], umpp2[key]);
        }
        return to_string(count) + "A" + to_string(count2) + "B";
    }
};