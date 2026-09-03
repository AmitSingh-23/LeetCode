class Solution {
public:
    int balancedString(string s) {
        unordered_map<char, int> umpp;
        unordered_map<char, int> umpp2;
        int n = s.length();
        for (int i = 0; i < s.length(); i++) {
            umpp[s[i]]++;
        }
        int opp = INT_MAX;

        int i = 0;
        int j = 0;
        if (umpp['Q'] == n / 4 && umpp['W'] == n / 4 && umpp['E'] ==
                                                 n / 4 && umpp['R'] == n / 4)
            return 0;
        while (j < n) {
            umpp[s[j]]--;
            while (i <= j && umpp['Q'] <= n / 4 && umpp['W'] <= n / 4 &&
                   umpp['E'] <= n / 4 && umpp['R'] <= n / 4) {
                opp = min(opp, j - i + 1);
                umpp[s[i]]++;
                i++;
            }
            j++;
        }

        return opp;
    }
};