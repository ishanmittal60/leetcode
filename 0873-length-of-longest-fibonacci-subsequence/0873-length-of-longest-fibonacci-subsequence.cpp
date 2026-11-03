class Solution {
public:
vector<vector<int>>dp;
int help(int i,int j,vector<int>& arr,unordered_map<int,int> &mp){
    if(dp[i][j]!=-1) return dp[i][j];
    int t=arr[j]-arr[i];
    if(mp.count(t) && mp[t]<i){
        int x= mp[t];
        return dp[i][j]= help(x,i,arr,mp)+1;
    }
    return 2;
}
    int lenLongestFibSubseq(vector<int>& arr) {
        int n=arr.size();
        dp.assign(n,vector<int>(n,-1));
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++) mp[arr[i]]=i;
        int ml=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<n;j++){
                int l = help(i,j,arr,mp);
                if(l>=3) ml=max(l,ml);
            }
        }
        return ml;
    }
};