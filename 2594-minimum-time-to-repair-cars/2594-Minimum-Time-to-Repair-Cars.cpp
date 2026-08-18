class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {

        int n = ranks.size();
   
        sort(ranks.begin(), ranks.end());
        long long i = 0;
        long long j = (long long)cars * cars * ranks[n - 1];
        long long  result = j;
        while (i <= j) {
            long long mid = (j - i) / 2 + i;
            long long  k = cars;

            for (int t = 0; t < ranks.size(); t++) {
                long long  done = sqrt(mid / ranks[t]);
            
                k = k - done;
                if(k<=0)break;
            }
            if (k <=0) {
                j = mid - 1;
                result = mid;
            } else {
                i = mid + 1;
            }
        }
        return result;
    }
};