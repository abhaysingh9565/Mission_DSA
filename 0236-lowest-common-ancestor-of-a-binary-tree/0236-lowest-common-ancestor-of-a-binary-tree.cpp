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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return nullptr;

        if(root==p || root == q)return root;

        TreeNode* lN = lowestCommonAncestor(root->left,p,q);
        TreeNode* rN = lowestCommonAncestor(root->right,p,q);

        if(rN && lN)return root;

        if(rN)return rN;

        else return lN;

    }
};