class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int zero = 0, ones = 0, two = 0;
        if (stones.size() == 1)
            return false;

        int result = false;
        for (int i = 0; i < stones.size(); i++) {
            stones[i] = stones[i] % 3;
            if (stones[i] == 0) {
                zero++;

            } else if (stones[i] == 1) {
                ones++;
            } else {
                two++;
            }
        }
        if (zero % 2 == 0) {

            return ones > 0 && two > 0;
        } else {

            return abs(ones - two) > 2;
        }
    }
};