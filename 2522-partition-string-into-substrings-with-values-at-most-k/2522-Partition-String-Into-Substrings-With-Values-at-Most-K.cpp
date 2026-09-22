class Solution {
public:
    int minimumPartition(string s, int k) {

        if (k < 10) {
            for (int i = 0; i < s.length(); i++) {
                if ((s[i] - '0') > k)
                    return -1;
            }
            return s.length();
        } else {
            int i = 0;
            int count = 0;

            while (i < s.length()) {
                long long current_val = 0;
                while (i < s.length() && current_val * 10 + (s[i] - '0') <= k) {
                    current_val = current_val * 10 + (s[i] - '0');
                    i++;
                }

                count++;
            }

            return count;
        }
    }
};