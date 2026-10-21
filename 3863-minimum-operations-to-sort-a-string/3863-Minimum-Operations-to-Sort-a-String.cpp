class Solution {
public:
    int minOperations(string s) {
        if (s.length() == 1)
            return 0;
        bool check = false;

        for (int i = 1; i < s.length(); i++) {
            if (s[i] < s[i - 1])
                check = true;
        }
        if (check) {
            if (s.length() <= 2) {
                return -1;
            }
            int small = 0;
            int lar = 0;
            for (int i = 0; i < s.length(); i++) {
                if (s[i] >= s[lar]) {
                    lar = i;
                }
                if (s[i] <s[small]) {
                    small = i;
                }
            }
          if (lar == 0 && small == s.length() - 1)
                return 3;
           if (small == 0 || lar == s.length() - 1)
    return 1;
            

                 return 2;

        } else
            return 0;
    }
};