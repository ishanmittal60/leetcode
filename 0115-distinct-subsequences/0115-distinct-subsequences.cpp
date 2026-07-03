class Solution {
public:
int re(string s, string t,int i , int j, vector<vector<int>> &dp ){
   if(j<0) return 1;
   if(i<0) return 0;
   if(dp[i][j] != -1) return dp[i][j];
   if(s[i]==t[j]) return dp[i][j] = re(s,t,i-1,j-1,dp)+re(s,t,i-1,j,dp);
   else return dp[i][j]= re(s,t,i-1,j,dp);
}
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
       // reverse(t.begin(),t.end());
    //     vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    //    return re(s,t,n-1,m-1,dp);
     vector<vector<unsigned long long>>dp(n+1,vector<unsigned long long>(m+1,0));
     for(int i = 0; i <= n; i++)
    dp[i][0] = 1;
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])  dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
   else dp[i][j]= dp[i-1][j];
        }
     }
     return dp[n][m];
    }
};