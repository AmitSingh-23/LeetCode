class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
       
        int m=nums.size();
        int n=nums[0].size();
         for(int i=0;i<m;i++){
  sort(nums[i].begin(),nums[i].end(),[](int a,int b){
            return a>b;
        });
         }
      
        int result=0;
        for(int j=0;j<n;j++){
            int t=INT_MIN;
            for( int i=0;i<m;i++){
                t=max(t,nums[i][j]);
            }
            result+=t;
        }
        return result;
    }
};