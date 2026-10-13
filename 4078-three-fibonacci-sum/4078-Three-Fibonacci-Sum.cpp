class Solution {
public:
    bool threeFibonacciSum(int n) {
        if (n % 2 != 0) return false;

        n /= 2;

        int a = 0, b = 1;

        while (a < n) {
            int c = a + b;
            a = b;
            b = c;
        }

        return a == n;
    }
};