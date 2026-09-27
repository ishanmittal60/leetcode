class Solution {
public:
vector<int> d,c;
vector<int>dp;
int n;
int help(int i){
if(i==n) return 0;
if(dp[i]!=-1) return dp[i];
int one =c[0]+ help(i+1);
int j = upper_bound(d.begin(),d.end(),d[i]+6)-d.begin();
int sev =c[1]+help(j);
int k= upper_bound(d.begin(),d.end(),d[i]+29)-d.begin();
int th= c[2]+help(k);
return dp[i]= min({one,sev,th});
}
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        d=days;
        c=costs;
        n=days.size();
        dp.assign(n+1,-1);
        return help(0);
    }
};