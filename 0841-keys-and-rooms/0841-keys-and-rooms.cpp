class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool>vis(n,false);
        vis[0]=true;
        int tot=1;
        queue<int>q;
    q.push(0);
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(int i=0;i<rooms[t].size();i++){
                 if(vis[rooms[t][i]]==false){ 
            q.push(rooms[t][i]);
           vis[rooms[t][i]]=true;
           tot++;
           }
            }
        }
        if(tot==n) return true;
        return false;
    }
};