class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adj(n);
        if(source == destination) return true;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        vector<bool>vis(n,false);
        q.push(source);
        vis[source] = true;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(int i=0;i<adj[t].size();i++){
                if(adj[t][i]==destination) return true;
                if(vis[adj[t][i]]==true) continue;
                else {
                    vis[adj[t][i]]=true;
                    q.push(adj[t][i]);}
            }
        }
        return false;
    }
};