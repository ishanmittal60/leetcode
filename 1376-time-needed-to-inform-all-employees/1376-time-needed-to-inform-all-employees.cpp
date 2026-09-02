class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]==-1) continue;
            adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>>q;
        q.push({headID,0});
        int ans=0;
        while(!q.empty()){
            auto [v , t] = q.front();
            q.pop();
            ans=max(ans,t);
            for(auto x : adj[v]){
                q.push({x,t+informTime[v]});
            }
        }
        return ans;
    }
};