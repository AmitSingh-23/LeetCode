class Solution {
public:
    int twoEggDrop(int n) {
        for (int i = 1; i < 1000; i++) {

            int curr = i;
            int total = n;
            int sum =( i * (i + 1)) / 2;
            if (sum >= n)
                return i;
        }
        return 0;
    }
};