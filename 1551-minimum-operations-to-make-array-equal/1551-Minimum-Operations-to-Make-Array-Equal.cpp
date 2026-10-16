class Solution {
public:
    int minOperations(int n) {
        int i=0;
        int j=n-1;
        int result=0;
        while(i<j){
            result+=j-i;
i++;
j--;
        }return result;
    }
};