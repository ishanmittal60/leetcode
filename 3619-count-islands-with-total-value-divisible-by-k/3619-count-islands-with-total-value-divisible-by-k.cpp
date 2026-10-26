class Solution {
public:
vector<vector<bool>> vis;
void help(vector<vector<int>>& grid, int i, int j, int k,long long &sum){
    int n = grid.size();
    int m = grid[0].size();
    if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0 || vis[i][j]) return;
    vis[i][j]=true;
    sum+=grid[i][j];
        help(grid, i + 1, j, k, sum);
        help(grid, i - 1, j, k, sum);
        help(grid, i, j + 1, k, sum);
        help(grid, i, j - 1, k, sum);
}
    int countIslands(vector<vector<int>>& grid, int k) {
        int n= grid.size();
        int m = grid[0].size();
        int ans=0;
        vis.assign(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0 && vis[i][j]==false){
                    long long sum=0;
                    help(grid,i,j,k,sum);
                    if(sum%k==0) ans++;
                }
            }
        }
        return ans;
    }
};