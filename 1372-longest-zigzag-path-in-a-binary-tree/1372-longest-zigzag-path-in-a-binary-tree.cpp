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
int mp=0;
void help(TreeNode* root,int st,bool g){
    if(root==NULL) return;
    mp=max(mp,st);
    if(g==true){
        help(root->left,st+1,false);
        help(root->right,1,true);
    }
     else{
        help(root->right,st+1,true);
        help(root->left,1,false);
    }
}
    int longestZigZag(TreeNode* root) {
        help(root,0,true);
        help(root,0,false);
        return mp;
    }
};