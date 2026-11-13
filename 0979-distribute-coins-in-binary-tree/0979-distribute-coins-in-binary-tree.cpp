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
int help(TreeNode* root, int &mv){
    if(root==nullptr) return 0;
    int l=help(root->left,mv);
    int r=help(root->right,mv);
    mv += abs(l) +abs(r);
    return (l+r+root->val)-1;
}
    int distributeCoins(TreeNode* root) {
        int mv=0;
        help(root,mv);
        return mv;
    }
};