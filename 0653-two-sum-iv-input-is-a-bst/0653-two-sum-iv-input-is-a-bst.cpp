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
    bool solve(TreeNode* root ,unordered_set<int>&st,int & k)
    {
        if(!root)return false;
        int rem = k-root->val;
        if(st.count(rem))return true;
        st.insert(root->val);

        return solve(root->left,st,k) || solve(root->right , st, k);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>st;
        return solve(root,st,k);
    }
};