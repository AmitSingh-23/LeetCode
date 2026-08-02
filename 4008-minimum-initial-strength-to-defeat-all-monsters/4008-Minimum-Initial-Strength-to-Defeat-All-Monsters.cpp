class Solution {
public:
    long long minInitialStrength(vector<int>& monsters, vector<vector<int>>& boosts) {
        int m=monsters.size();
        vector<long  long>vt(m+1,0);
        for(int i=0;i<boosts.size();i++){
            int start=boosts[i][0];
            int end=boosts[i][1];
            vt[start]+=boosts[i][2];
            vt[end+1]-=boosts[i][2];
        }
        
        for(int i=1;i<m+1;i++){
            vt[i]+=vt[i-1];
        }
       long long left=0;
         long long ans=0;
        long long right=LLONG_MAX;
        while(left<=right){
            long long mid=left+(right-left)/2;
if(check(mid,monsters,vt)){
    ans=mid;
    right=mid-1;
    
}
            else{
                left=mid+1;
            }
            
        }
        return ans;
    }
    bool check(long long initial,vector<int>& monsters, vector<long long>& vt ){
        long long k=initial;
        for(int i=0;i<monsters.size();i++){
            if(k+vt[i]<monsters[i]){
            return false;
            }
            k=k-monsters[i];
            if(k<0){
                k=0;
            }
        }
        return true;
    }
};