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
    vector<vector<int>>ans;

    void solve(TreeNode* root, int Sum,vector<int>&temp,int &targetSum)
    {
        if (!root)return;

        Sum+=root->val;
        temp.push_back(root->val);

        if(root->left == NULL && root->right == NULL ){
            if(Sum==targetSum)ans.push_back(temp);
        }
        else{
        solve(root->left,Sum,temp,targetSum);
        solve(root->right,Sum,temp,targetSum);
        }

        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum=0;
        vector<int>temp;
        solve(root,sum,temp,targetSum);


        return ans;
        
    }
};