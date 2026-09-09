class Solution {
public:
    long long countCommas(long long n) {
        if(n<=999)return 0;
        if(n<1e6)return n-999;
        if(n<1e9)return 2*(n-1e6+1)+1e6-1e3; 
        if(n<1e12)return 3*(n-1e9+1)+2*(1e9-1e6)+1e6-1e3;
        if(n<1e15) return 4*(n-1e12+1)+3*(1e12-1e9)+2*(1e9-1e6)+1e6-1e3;
         return 4*(n-1e12+1)+3*(1e12-1e9)+2*(1e9-1e6)+1e6-1e3+1;
        
    }
};