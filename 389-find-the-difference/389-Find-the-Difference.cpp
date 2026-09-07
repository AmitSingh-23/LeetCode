class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> umpp;
        for (auto it : t) {
            umpp[it]++;
        }
        for (auto it : s) {
            umpp[it]--;
        }
        for (auto [key, value] : umpp) {
            if (value > 0)
                return key;
        }
        return 'a';
    }
};