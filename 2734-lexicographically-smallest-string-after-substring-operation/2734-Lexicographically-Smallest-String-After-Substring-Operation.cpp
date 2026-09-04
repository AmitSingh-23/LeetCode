class Solution {
public:
    string smallestString(string s) {
        int n = s.length();
        bool found = false;
        int start = 0;
        while (start < s.length()) {
            if (s[start] != 'a') {

                break;
            }
            start++;
        }
        if (start == n) {
            s[n - 1] = (char)('a' + (25 + s[n - 1] - 'a') % 26);
            return s;
        }
        while (start < n && s[start] != 'a') {
            s[start] = (char)('a' + (25 + s[start] - 'a') % 26);
            start++;
        }
        return s;
    }
};