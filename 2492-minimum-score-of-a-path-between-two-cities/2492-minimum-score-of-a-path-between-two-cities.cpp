class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto &r : roads) {
            int u = r[0];
            int v = r[1];
            int w = r[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        vector<bool>vis(n+1);
        int ans = INT_MAX;
        queue<int>q;
        q.push(n);
        vis[n] = true;
        while(!q.empty()){
            int j = q.front();
            q.pop();
             for (auto &[v, w] : adj[j]){
                 ans= min(ans,w);
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                   
                }
            }
        }
        return ans;
    }
};