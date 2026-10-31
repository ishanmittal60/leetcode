
class Solution {
public:
    int m, n;
    const int MOD = 1e9 + 7;

    vector<vector<vector<int>>> dp;
    int help(int i, int j, int dir, vector<vector<int>>& grid) {
        if (i>=m || j>=n) return 0;
        if (i == m-1 && j == n-1) return 1;
        if (dp[i][j][dir] != -1) return dp[i][j][dir];

        int ans=0;

        if (grid[i][j]==1) {
            if (dir==0) ans=help(i+1,j,1,grid);
            else ans = help(i,j+1,0,grid);

        }
        else {
            ans += help(i, j+1, 0, grid);
             ans = (ans + help(i+1, j, 1, grid)) % MOD;
        }

        return dp[i][j][dir] = ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(2, -1)));

        return help(0, 0, 0, grid);
    }
};
