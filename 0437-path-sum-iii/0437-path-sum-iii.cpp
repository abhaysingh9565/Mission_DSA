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
    int count = 0 ;
    private:
    void solve(TreeNode* root , int targetSum , long sum )
    {
        if(!root)return ;

        sum+=root->val;

        if(sum==targetSum)
        {
            count++;
        }
        solve(root->left,targetSum , sum);
        solve(root->right, targetSum , sum);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        if(!root)return 0 ;

        solve(root,targetSum , 0 );

        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        
        return count;
    }
};