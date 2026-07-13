class Solution {
public:
int f(vector<int>& prices,int ind ,int b,vector<vector<int>> &dp, int fe){
    if(ind>=prices.size()) return 0;
    
    if(dp[ind][b] != -1) return dp[ind][b];
    int p=0;
    if(b==1){
        p+=max((-prices[ind]+f(prices,ind+1,0,dp,fe)),f(prices,ind+1,1,dp,fe));
    }
    else{
        p+=max((prices[ind]+f(prices,ind+1,1,dp,fe)-fe),f(prices,ind+1,0,dp,fe));
    }
    return dp[ind][b] =  p;
}
    int maxProfit(vector<int>& prices, int fee) {
           vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
       return f(prices,0,1,dp,fee);
    }
};