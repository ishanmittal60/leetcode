class Solution {
public:
vector<int>dp;
int help(int i,int n, vector<int>& costs){
    if(i==n) return 0;
    if(dp[i]!=-1) return dp[i];
    int ans=INT_MAX;
    for(int j=i+1;j<=min(i+3,n);j++){
        int curr = costs[j-1]+(j-i)*(j-i)+help(j,n,costs);
        ans =min(ans,curr);
    }
    return dp[i]= ans;
}
    int climbStairs(int n, vector<int>& costs) {
        dp.assign(n+1,-1);
        return help(0,n,costs);
    }
};