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
    private:
    void solve(TreeNode* root,vector<vector<int>>&ans , vector<int>&path , int sum , int targetSum)
    {
        if(!root)return ;
        sum += root->val;
        path.push_back(root->val);
        if(!root->left && !root->right && sum==targetSum)
        {
            ans.push_back(path);
        }
        else{
        if(root->left)solve(root->left,ans,path,sum , targetSum);
        if(root->right)solve(root->right,ans,path,sum , targetSum);
        }
        path.pop_back();

    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root)return {};

        vector<vector<int>>ans;
        vector<int>path;
        int sum = 0 ;
        solve(root , ans , path , sum , targetSum);

        return ans;
    }
};