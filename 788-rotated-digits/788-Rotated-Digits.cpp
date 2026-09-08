class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (check(i))
                count++;
        }
        return count;
    }
    bool check(int i) {

        bool diff = false;

        while (i != 0) {
            int k = i % 10;
            if (k == 3 || k == 4 || k == 7)
                return false;
            else if (k == 5 || k == 2 || k == 9 || k == 6) {
                diff = true;
            }
            i=i/10;

          
        }
          return diff;
    }
};