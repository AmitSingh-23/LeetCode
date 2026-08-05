class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long > dp(questions.size(), -1);
        return check(dp,0,questions);
    }
    long long  check(vector<long long >&dp,int i,vector<vector<int>>& qt){
        if (i >= dp.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        long long take = (long long)qt[i][0] + check(dp, i + qt[i][1]+1, qt);
        long long nottake = check(dp, i + 1, qt);
       if(take>nottake)return dp[i]=take;
        return dp[i]=nottake;
    }
};