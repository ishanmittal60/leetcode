class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;

        int odd = 0;
        int even = 1;
        int sum = 0;
        int ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (sum % 2 == 1) {
                ans = (ans + even) % MOD;
                odd++;
            }
            else {
                ans = (ans + odd) % MOD;
                even++;
            }
        }

        return ans;
    }
};