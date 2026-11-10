class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze[0].size();
        int m=maze.size();
        int dr[4]={-1,0,1,0};
        int dc[4]={0,-1,0,1};
        queue<pair<int,pair<int,int>>>p;
        p.push({0,{entrance[0],entrance[1]}});
        while(!p.empty()){
            auto curr = p.front();

int step = curr.first;
int x = curr.second.first;
int y = curr.second.second;

p.pop();
                if((x==0 || x==m-1|| y==0 || y==n-1)&&!(x==entrance[0] && y==entrance[1])) return step;
            
            for(int i=0;i<4;i++){
                int nr=x+dr[i];
                int nc=y+dc[i];
                if(nr<0 || nr>=m|| nc<0 ||nc>=n) continue;
                if(maze[nr][nc]=='+'){
                    continue;
                }
                maze[nr][nc]='+';
                 p.push({step+1,{nr,nc}});
            }
        }
        return -1;
    }
};