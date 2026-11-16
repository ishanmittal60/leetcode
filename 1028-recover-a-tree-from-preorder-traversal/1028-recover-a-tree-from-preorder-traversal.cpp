/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     Treehttps://assets.leetcode.com/uploads/2024/09/10/recover_tree_ex2.png$0Node(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int n;
 TreeNode* help(string &s, int &i, int d){
    if(i>=n) return nullptr;
    int j=i;
    while(j<n && s[j]=='-'){
        j++;
    }
    int dash=j-i;
    if(dash!=d) return nullptr;
    i+=dash;
    int num=0;
    while(i<n&&isdigit(s[i])){
        num=num*10+(s[i]-'0');
        i++;
    }
    TreeNode* root =new TreeNode(num);
    root->left = help(s,i,d+1);
    root->right = help(s,i,d+1);
    return root;
 }
    TreeNode* recoverFromPreorder(string traversal) {
        n=traversal.size();
        int i=0;
        int d=0;
        return help(traversal,i,d);
    }
};