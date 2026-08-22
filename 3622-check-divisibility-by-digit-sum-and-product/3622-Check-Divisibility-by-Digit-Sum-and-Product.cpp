class Solution {
public:
    bool checkDivisibility(int n) {

        int m = n;
        long long multi = 1;
        long long sum = 0;
        while (m != 0) {
            sum +=   m % 10;
            multi *= m % 10;
            m = m / 10;
        }
        return (n%(multi +sum) == 0) ? true : false;
    }
};