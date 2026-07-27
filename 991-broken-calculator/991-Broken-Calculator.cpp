class Solution {
public:
    int brokenCalc(int startValue, int target) {
        if(target<startValue)return startValue-target;
        int n=target;
        int steps=0;
        int m=startValue;
int count=0;
      

        while(m!=n){
              if(n%2!=0){
                n=n+1;
                count++;
              }

              n=n/2;
              count++;
              if(n<m){
                count+=m-n;
                break;
              }

              


        }
        return count;
    }
};