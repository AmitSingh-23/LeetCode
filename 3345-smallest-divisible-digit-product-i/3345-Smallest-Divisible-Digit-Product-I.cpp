class Solution {
public:
    int smallestNumber(int n, int t) {
        while (n <= 100) {
            int val = check(n) % t;
            if (val % t == 0)
                return n;
                n++;
        }
        return 0;
    }
    int check(int n) {
        int product = 1;
        while (n != 0) {
            product = product * (n % 10);
            n = n / 10;
        }
        return product;
    }
};