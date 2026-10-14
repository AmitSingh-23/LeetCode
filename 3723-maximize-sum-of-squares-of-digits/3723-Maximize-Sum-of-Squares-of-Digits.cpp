class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        if (sum > num * 9)
            return "";
        while (num != 0) {
            int dig=min(sum,9);
          ans+= char('0'+dig);
            sum = sum - min(sum, 9);
            num--;
        }

        return ans;
    }
};