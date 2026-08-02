class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int m=nums.size();
       vector<int>vt;
        unordered_map<int,int>umpp;
       
        for(int i=0;i<m;i++){
            if(umpp[nums[i]]==0)vt.push_back(nums[i]);
            umpp[nums[i]]++;
        }
         vector<int>dp(vt.size(),-1);
        sort(vt.begin(),vt.end());
        return check(vt,umpp,0,dp);

    }
    int check(vector<int>&vt,unordered_map<int,int>&umpp,int i,vector<int>&dp){
        if(i>=vt.size())return 0;

        if(dp[i]!=-1)return dp[i];
        int next=i+1;
        if(vt.size()>next&&vt[next]==vt[i]+1){
            next=i+2;
        }

        dp[i]=max(umpp[vt[i]]*vt[i]+check(vt,umpp,next,dp),check(vt,umpp,i+1,dp));
    
        return dp[i];

    }
};