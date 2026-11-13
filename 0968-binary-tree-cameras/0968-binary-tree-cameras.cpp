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
//need -1 , covered 1, have 0
int cnt=0;
int help(TreeNode* root){
    if(!root) return 1;
    int l = help(root->left);
    int r=help(root->right);
    if(l==-1 || r==-1) {
        cnt++;
        return 0;
    }
    if(l==0 || r==0) return 1;
    return -1;
}
    int minCameraCover(TreeNode* root) {
        if(help(root)== -1) cnt++;
        return cnt;
    }
};