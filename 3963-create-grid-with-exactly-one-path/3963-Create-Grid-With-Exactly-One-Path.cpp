class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> vt(m,string(n,'#'));
        for(int i =1;i<m;i++){
            
            vt[i][n-1]='.';
        }
        for(int j=0;j<n;j++){
            vt[0][j]='.';
        }
        return vt;
        
        
    }
};