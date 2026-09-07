class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for(int i=0;i<n;i++) mp[arr[i]].push_back(i);
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int> vis(n, 0);
        vis[0] =1;
        while(!q.empty()){
            int u = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if (u == n - 1)
                return cnt;
            if(u-1>=0 && vis[u-1]==0){
                vis[u-1]=1;
                q.push({u-1,cnt+1});
            } 
            if (u+1<n && !vis[u+1]) {
                vis[u+1] = 1;
                q.push({u+1,cnt+1});
            }
            for (int v : mp[arr[u]]) {
                if (!vis[v]) {
                    vis[v] = 1;
                    q.push({v, cnt+1});
                }
            }
            mp[arr[u]].clear();
        }
        return -1;
    }
};