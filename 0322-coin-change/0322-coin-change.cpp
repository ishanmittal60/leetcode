class Solution {
public:
int re(vector<int>& coins, int a , int ind,  vector<vector<int>> &dp){
if(ind==0){
    if(a%coins[ind]==0) return a/coins[ind];
    else return 1e9;
}
if(dp[ind][a]!=-1) return dp[ind][a];
int nt = re(coins,a,ind-1,dp);
int t = INT_MAX;
if(coins[ind]<=a){
    t = 1 + re(coins,a-coins[ind],ind,dp);
}
return dp[ind][a] =  min(t,nt); 
}
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
//         vector<vector<int>>dp(n,vector<int>(amount+1,-1));
// int ans = re(coins, amount, n-1,dp);


// if(ans >= 1e9)
//     return -1;

// return ans;
vector<vector<int>>dp(n,vector<int>(amount+1,0));
for(int a = 0; a <= amount; a++) {

    if(a % coins[0] == 0)
        dp[0][a] = a / coins[0];
    else
        dp[0][a] = 1e9;
}
for(int i =1;i<n;i++){
    for(int a = 0;a<=amount;a++){
       
int nt = dp[i-1][a];
int t = INT_MAX;
if(coins[i]<=a){
    t = 1 + dp[i][a-coins[i]];
}
dp[i][a] =  min(t,nt);
    }
}
int ans = dp[n-1][amount];
if(ans >= 1e9)
     return -1;

 return ans;
    }
};