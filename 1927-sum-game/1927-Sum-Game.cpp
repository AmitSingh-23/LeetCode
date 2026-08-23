class Solution {
public:
    bool sumGame(string num) {
        int leftsum = 0;
        int rightsum = 0;
        int left = 0;
        int right = 0;
        int n = num.length();

        for (int i = 0; i < n; i++) {
            if (i < n / 2) {
                if (num[i] == '?')
                    left++;
                else {
                    leftsum += num[i] - '0';
                }

            } else {
                if (num[i] == '?')
                    right++;
                else {
                    rightsum += num[i] - '0';
                }
            }
        }

        if (left == right)
            return (leftsum == rightsum) ? false : true;
        if ((left + right) % 2 != 0)
            return true;
        int peakl = leftsum + left * 9;
        int peakr = rightsum + right * 9;
        if (peakl == peakr)
            return true;
        int diff = abs(peakl - peakr);
        if (peakr > peakl) {
            if (right < left)
                return true;
            else {
                right = right - left;

                int bob = right / 2;
                if (bob * 9 == diff)
                    return false;
            }
        } else {
            if (right > left)
                return true;
            else {
                left = -right + left;

                int bob = left / 2;
                if (bob * 9 == diff)
                    return false;
            }
        }
        return true;
    }
};