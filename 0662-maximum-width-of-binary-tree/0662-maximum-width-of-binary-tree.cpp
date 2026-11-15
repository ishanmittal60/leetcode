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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long mw=0;
        while(!q.empty()){
            long long r=q.front().second;
            long long l=q.back().second;
            mw=max(mw,l-r+1);
            long long n=q.size();
            while(n--){
              TreeNode* t =q.front().first;
                long long idx=q.front().second-r;
                q.pop();
                if(t->left) q.push({t->left,2*idx+1});
                if(t->right) q.push({t->right,2*idx+2});
            }
        }
        return (int)mw;
    }
};