class Solution {
public:
    int numSub(string s) {
        long long n = 0;
        long long result = 0;
        int mod=1e9+7;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1'){
                n++;
                n=n%mod;
                 result += n ;
                 }
            else {
             
                n = 0;
            }
        }
        return result%mod;
    }
};