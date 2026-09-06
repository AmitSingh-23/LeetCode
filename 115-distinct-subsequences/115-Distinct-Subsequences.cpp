class Solution {
public:
    int numDistinct(string s, string t) {
         vector<vector<int>> dp(s.length(),vector<int>(t.length(),-1));
        return check(s,t,s.length()-1,t.length()-1,dp);
    }
    long long check(string &s, string &t,int i,int j,vector<vector<int>> &dp)
    {    
        if (i<0)return 0;
        if (j<0)return 1;
        else if(i==0){
            if (j==0)return s[i]==t[j];
            return 0;  
            }
        
        if (dp[i][j]!=-1)return dp[i][j];
        int take=0;
        if (s[i]==t[j]) take=check(s,t,i-1,j-1,dp);
        int noti=check(s,t,i-1,j,dp);
        return dp[i][j]=noti+take;
       
        }
    };