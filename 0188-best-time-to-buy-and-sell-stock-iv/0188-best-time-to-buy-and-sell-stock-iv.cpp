class Solution {
public:
int f(vector<int>& prices,int ind ,int b,int c,vector<vector<vector<int>>> &dp){
    if(ind==prices.size()) return 0;
    if(c==0) return 0;
    if(dp[ind][b][c] !=-1) return dp[ind][b][c];
    int p=0;
    if(b==1){
        p+=max((-prices[ind]+f(prices,ind+1,0,c,dp)),f(prices,ind+1,1,c,dp));
    }
    else{
        p+=max((prices[ind]+f(prices,ind+1,1,c-1,dp)),f(prices,ind+1,0,c,dp));
    }
    return dp[ind][b][c] =  p;
}
    int maxProfit(int k , vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(prices,0,1,k,dp); 
    }
};