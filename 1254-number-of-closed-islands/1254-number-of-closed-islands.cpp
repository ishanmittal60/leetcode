class Solution {
public:
    vector<vector<bool>> vis;

    void help(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m)
            return;

        if (grid[i][j] == 1 || vis[i][j])
            return;

        vis[i][j] = true;

        help(grid, i + 1, j);
        help(grid, i - 1, j);
        help(grid, i, j + 1);
        help(grid, i, j - 1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vis.assign(n, vector<bool>(m, false));

        // Step 1: Eliminate islands connected to boundaries
        for (int i = 0; i < n; i++) {
            help(grid, i, 0);
            help(grid, i, m - 1);
        }

        for (int j = 0; j < m; j++) {
            help(grid, 0, j);
            help(grid, n - 1, j);
        }

        // Step 2: Count remaining closed islands
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !vis[i][j]) {
                    count++;
                    help(grid, i, j);
                }
            }
        }

        return count;
    }
};