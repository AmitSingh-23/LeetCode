class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int m=A.size();
        vector<int>result(m,0);
       vector<int>tally(m+1,0);
       int count=0;
        for(int i=0;i<m;i++){
            tally[A[i]]++;
            if(tally[A[i]]==2)count++;
            tally[B[i]]++;
            if(tally[B[i]]==2)count++;
            result[i]=count;

            
        }
        return result;
    }
};