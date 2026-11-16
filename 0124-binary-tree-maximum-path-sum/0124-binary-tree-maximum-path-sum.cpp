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
int mv=INT_MIN;
int help(TreeNode* root){
    if(!root) return 0;
    int l = max(0, help(root->left));
int r = max(0, help(root->right));
    int a=root->val+l+r;
    mv=max(a,mv);
    return root->val+ max(l,r);
}
    int maxPathSum(TreeNode* root) {
        help(root);
        return mv;
    }
};