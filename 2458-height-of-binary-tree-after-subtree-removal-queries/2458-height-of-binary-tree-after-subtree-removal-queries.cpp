/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> h, d, lh1, lh2;
int help(TreeNode* root, int k){
if(!root) return 0;
d[root->val]=k;
h[root->val]=max(help(root->right,k+1),help(root->left,k+1))+1;
 if (lh1[k] < h[root->val]) {
            lh2[k] = lh1[k];
            lh1[k] = h[root->val];
        }
        else if (lh2[k] < h[root->val]) {
            lh2[k] = h[root->val];
        }
return h[root->val];
}
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
         int n = 100001;

        h.assign(n, 0);
        d.assign(n, 0);
        lh1.assign(n, 0);
        lh2.assign(n, 0);

        help(root, 0);

        vector<int> res;

        for (int q : queries) {
            int L = d[q];

            int temp = L + (lh1[L] == h[q] ? lh2[L] : lh1[L]) - 1;

            res.push_back(temp);
        }

        return res;
    }
};