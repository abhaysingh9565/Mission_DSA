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
    void inorder(TreeNode* root ,vector<int>&arr)
    {
        if(root)
        {
            inorder(root->left , arr);
            arr.push_back(root->val);
            inorder(root->right , arr);
        }
        
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int>arr;
        inorder(root,arr);
        int s = 0 , e = arr.size()-1;
        int sum;
        while(s<e)
        {
            sum = arr[s]+arr[e];
            if(sum == k)
            {
                return true;
            }
            else if(sum < k)
            {
                s++;
            }
            else{
                e--;
            }
        }
        return false;
    }
};