class Solution {
public:
    int m, n;
    vector<vector<char>> g;
    vector<vector<vector<int>>> dp;

    bool isv(int i, int j, int balance) {

        if (g[i][j] == '(')
            balance++;
        else
            balance--;

        if (balance < 0)
            return false;

        int remaining = (m - 1 - i) + (n - 1 - j);

        if (balance > remaining)
            return false;

        if (i == m - 1 && j == n - 1)
            return balance == 0;

        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        bool ans = false;

        if (i + 1 < m)
            ans = ans || isv(i + 1, j, balance);

        if (j + 1 < n)
            ans = ans || isv(i, j + 1, balance);

        return dp[i][j][balance] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        g = grid;
        m = g.size();
        n = g[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        // Maximum possible balance is m+n
        dp.assign(m,
                  vector<vector<int>>(
                      n,
                      vector<int>(m + n + 1, -1)));

        return isv(0, 0, 0);
    }
};