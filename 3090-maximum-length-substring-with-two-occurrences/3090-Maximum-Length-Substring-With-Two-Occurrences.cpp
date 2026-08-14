class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> umpp;
        int j = 0;
        int result = 1;
        for (int i = 0; i < s.length(); i++) {
            umpp[s[i]]++;
            while (umpp[s[i]] > 2) {
                umpp[s[j]]--;
                j++;
            }
            result = max(result, i - j + 1);
        }
        return result;
    }
};