class Solution {
public:
int re(int n , string &s, vector<int> &dp,int i){
    if(i==n) return 1;
    if(s[i] == '0') return 0;

        if(dp[i] != -1) return dp[i];
    int res = re(n,s,dp,i+1);
    if(i+1 < n &&
   (s[i]=='1' ||
   (s[i]=='2' && s[i+1]<='6'))){
        res+=re(n,s,dp,i+2);
    }
    dp[i] = res;
    return dp[i]=res;
}
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n+1,-1);
        return re(n,s,dp,0);
    }
};