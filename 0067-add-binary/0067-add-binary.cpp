class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size();
        int n2 = b.size();
        int i = n1 - 1;
        int j = n2 - 1;
        char c = '0';
        string ans;
        while (i >= 0 || j >= 0) {

            char x = (i >= 0) ? a[i] : '0';
            char y = (j >= 0) ? b[j] : '0';

            // 0 + 0
            if (x == '0' && y == '0' && c == '0') {
                ans += '0';
                c = '0';
            }

            // 0 + 0 + carry
            else if (x == '0' && y == '0' && c == '1') {
                ans += '1';
                c = '0';
            }

            // 0 + 1 or 1 + 0, no carry
            else if ((x == '0' && y == '1' && c == '0') ||
                     (x == '1' && y == '0' && c == '0')) {
                ans += '1';
                c = '0';
            }

            // 0 + 1 + carry or 1 + 0 + carry
            else if ((x == '0' && y == '1' && c == '1') ||
                     (x == '1' && y == '0' && c == '1')) {
                ans += '0';
                c = '1';
            }

            // 1 + 1, no carry
            else if (x == '1' && y == '1' && c == '0') {
                ans += '0';
                c = '1';
            }

            // 1 + 1 + carry
            else if (x == '1' && y == '1' && c == '1') {
                ans += '1';
                c = '1';
            }

            i--;
            j--;
        }
        if (c == '1')
            ans += '1';

        reverse(ans.begin(), ans.end());

        return ans;
    }
};