/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(!root){return NULL;}
        help(root, 0);
        return root;
    }
    
    void help(TreeNode* root, int ex)
    {
        if(!root){return;}
        root->val = sum(root->right) + root->val + ex;
        help(root->right, ex);
        help(root->left, root->val);
    }
    
    int sum(TreeNode* p)
    {
        if(p == NULL){return 0;}
        return sum(p->left) + p->val + sum(p->right);
    }
};