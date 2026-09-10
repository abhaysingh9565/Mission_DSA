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
    void inorder(TreeNode* root , vector<int>& ans)
    {
        if(root)
        {
            inorder(root->left, ans);
            ans.push_back(root->val);
            inorder(root->right , ans);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        // inorder(root, ans);

        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty())
        {
            if(root)
            {
                st.push(root);
                root = root->left;
            }
            else{
                root=st.top();
                st.pop();
                ans.push_back(root->val);
                root=root->right;
            }
        }
        ans.pop_back();
        return ans;
    }
};