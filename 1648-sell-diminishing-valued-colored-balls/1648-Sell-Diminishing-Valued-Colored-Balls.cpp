class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        sort(inventory.begin(), inventory.end(),[](int a,int b){
            return a>b;
        });
        inventory.push_back(0);
        long long mval = inventory[0];
        long long count = 1;
        long long result = 0;
        int mod = 1e9 + 7;
        for (int i = 1; i < inventory.size() && orders != 0; i++) {
            long long  val = inventory[i];
            if(count*(mval-val)<=orders){
                result += count * (mval * (mval + 1) / 2 - val*(val + 1) / 2);
                result = result % mod;
                orders -= count * (mval - val);
            }
            else{
                long long  stop = mval - orders / count;
                result += count * (mval * (mval + 1) / 2 - stop*(stop + 1) / 2);
                result = result % mod;
                orders -= count * (mval - stop);

                if (orders <= count) {
                    result += orders * stop;
                    result = result % mod;
                    orders = 0;
                }
                
            }
       
           count++;
           mval=val;
        }
         

        return result % mod;
    }
};