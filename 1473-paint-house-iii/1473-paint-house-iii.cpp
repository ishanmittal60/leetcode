class Solution {
public:
    int n, m, t;
    vector<int> h;
    vector<vector<int>> c;
    vector<vector<vector<int>>> dp;

    int help(int idx, int prev, int tot) {
        if (tot > t)
            return 1e9;

        if (idx == n) {
            if (tot == t)
                return 0;
            return 1e9;
        }

        if (dp[idx][prev][tot] != -1)
            return dp[idx][prev][tot];

        int ans = 1e9;

        // Already painted
        if (h[idx] != 0) {

            if (h[idx] == prev) {
                ans = help(idx + 1, prev, tot);
            }
            else {
                ans = help(idx + 1, h[idx], tot + 1);
            }
        }

        // Not painted
        else {

            for (int color = 1; color <= m; color++) {

                int newGroups = tot;

                if (color != prev)
                    newGroups++;

                ans = min(ans,
                    c[idx][color - 1] +
                    help(idx + 1, color, newGroups));
            }
        }

        return dp[idx][prev][tot] = ans;
    }

    int minCost(vector<int>& houses,
                vector<vector<int>>& cost,
                int m1,
                int n1,
                int target) {

        h = houses;
        c = cost;

        // LC 1473:
        // m1 = number of houses
        // n1 = number of colors
        n = m1;
        m = n1;
        t = target;

        dp.assign(n,
                  vector<vector<int>>(
                      m + 1,
                      vector<int>(t + 1, -1)));

        int ans = help(0, 0, 0);

        return ans == 1e9 ? -1 : ans;
    }
};