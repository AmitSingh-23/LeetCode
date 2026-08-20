class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int n = houses.size();
        int i = 0;
        int j = 1000000000;
        int result = j;
        while (i <= j) {
            int mid = (j - i) / 2 + i;
            int f = 0;
            for (int k = 0; k < heaters.size(); k++) {

                while (f < houses.size()) {
                    int val = heaters[k];

                    if (heaters[k] - mid <= houses[f] &&
                        heaters[k] + mid >= houses[f]) {
                        f++;
                    } else {
                        break;
                    }
                }
            }
            if (f == houses.size()) {
                result = mid;
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        return result;
    }
};