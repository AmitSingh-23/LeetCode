class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end());
        int prev = 0;
        int result = 0;
        for (int i = 0; i < reservedSeats.size(); i++) {
            int curr = reservedSeats[i][0];
            result += (curr - prev - 1) * 2;
            bool left, right, mid;
            left = right = mid = true;
            while (i < reservedSeats.size() && reservedSeats[i][0] == curr) {
                int seat = reservedSeats[i][1];
                if (seat >= 2 && seat <= 5)
                    left = false;
                if (seat >= 4 && seat <= 7)
                    mid = false;
                if (seat >= 6 && seat <= 9)
                    right = false;
                i++;
            }
            i--;
            if (left && right) {
                result += 2;
            } else if (left || right || mid) {
                result += 1;
            }
            prev = curr;
        }
        result+=(n-prev)*2;
        return result;
    }
};