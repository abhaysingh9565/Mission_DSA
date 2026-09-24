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
    int totalSum = 0 ;
    void solve(TreeNode* root,int sum = 0)
    {
        if(!root)
        {
            return ;
        }
        sum = sum*10+root->val;
        if(!root->left && !root->right)
        {
            totalSum += sum;
            return ;
        }
        solve(root->left,sum);
        solve(root->right,sum);

    }
    int sumNumbers(TreeNode* root) {
        solve(root);
        return totalSum;
    }
};