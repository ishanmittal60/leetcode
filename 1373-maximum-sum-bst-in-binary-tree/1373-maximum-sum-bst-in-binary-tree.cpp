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
int maxs;
struct info{
    bool is;
    int mn,mx,sum;
};
info help(TreeNode* root){
    if(!root) return {true, INT_MAX, INT_MIN, 0};
    info l = help(root->left);
    info r = help(root->right);
    if(l.is&& r.is && root->val>l.mx &&root->val<r.mn){
         int sum = l.sum + r.sum + root->val;
            maxs = max(maxs, sum);
            return {true, min(root->val, l.mn), max(root->val, r.mx),sum};
    }
    return {false, INT_MIN, INT_MAX, 0};
}
    int maxSumBST(TreeNode* root) {
        maxs=0;
        help(root);
        return maxs;
    }
};