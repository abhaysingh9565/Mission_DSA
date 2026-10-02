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
    void preorder(TreeNode* root , vector<TreeNode*>& arr)
    {
        if(root)
        {
            arr.push_back(root);
            preorder(root->left,arr);
            preorder(root->right,arr);
        }
    }
public:
    void flatten(TreeNode* root) {
        if(!root)return;
        vector<TreeNode*>arr;
        preorder(root,arr);
        for(int i = 0 ; i < arr.size()-1;i++)
        {
            arr[i]->left = NULL;
            arr[i]->right = arr[i+1];
        }
        arr[arr.size()-1]->right = NULL;

    }
};