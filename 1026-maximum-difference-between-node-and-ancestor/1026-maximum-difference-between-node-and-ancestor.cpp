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
int md=0;
void help(TreeNode* root, int ma, int mi){
if(!root) return ;
int nma =max(root->val,ma);
int nmi = min(root->val,mi);
md=max(md,abs(nma-nmi));
help(root->left,nma,nmi);
help(root->right,nma,nmi);
}
    int maxAncestorDiff(TreeNode* root) {
         help(root,root->val,root->val);
         return md;
    }
};