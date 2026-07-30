class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int m= nums.size();
        vector<vector<int>>dp(m,vector<int>(m+1,-1));
        return check(dp,0,-1,nums);
    }
    int check(vector<vector<int>> &dp,int i,int prev,vector<int>& nums){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][prev+1]!=-1)return dp[i][prev+1]; 
   int left=0;
       if(prev==-1||nums[prev]<nums[i]){
      dp[i][prev+1]=max(dp[i][prev+1],1+check(dp,i+1,i,nums));
       }
      dp[i][prev+1]=max(dp[i][prev+1],check(dp,i+1,prev,nums));
       return dp[i][prev+1];




    }
};