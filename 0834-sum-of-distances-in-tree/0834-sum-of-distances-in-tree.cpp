class Solution {
public:
long long res=0;
int n;
vector<int>cnt;
int dfs(unordered_map<int,vector<int>> &adj, int curr,int prev,int d){
    int tot=1;
    res+=d;
    for(int &child : adj[curr]){
        if(child == prev) continue;
         tot+= dfs(adj,child,curr,d+1);
    }
    cnt[curr] =tot;
    return tot;
}

void g(unordered_map<int, vector<int>> &adj, int par,int prev, vector<int>& r){
     for(int &child : adj[par]){
        if(child == prev) continue;
        r[child]=r[par]-cnt[child]+(n-cnt[child]);
        g(adj,child,par,r);
     }
}
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        n=N;
        cnt.assign(n, 0);
        for(auto &e : edges){
    adj[e[0]].push_back(e[1]);
    adj[e[1]].push_back(e[0]);
}
        dfs(adj,0,-1,0);
        vector<int>ans(n,0);
        ans[0]=res;
       g(adj,0,-1,ans);
       return ans;
    }
};