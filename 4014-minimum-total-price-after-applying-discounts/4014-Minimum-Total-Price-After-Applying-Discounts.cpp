class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end(), [](int a, int b) { return a > b; });
        sort(discounts.begin(), discounts.end(),
             [](int a, int b) { return a > b; });
        int i = 0;
        int j = 0;
        int m = prices.size();
        int n = discounts.size();
        double sum = 0;
        while (i < m && j < n) {
            double cost = prices[i];
            double dis = discounts[j];
            sum += (cost * (100 - dis)) / 100;
            i++;
            j++;
        }
        while (i < m) {
            sum += prices[i];
            i++;
        }
        return sum;
    }
};