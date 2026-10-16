class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0;

        arr.push_back(0);

        int j = arr.size() - 1;
        while (i <= j) {
            int mid = (j - i) / 2 + i;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            if (arr[mid] > arr[mid - 1]) {
                i = mid;

            } else {
                j = mid;
            }
        }
        return 0;
    }
};