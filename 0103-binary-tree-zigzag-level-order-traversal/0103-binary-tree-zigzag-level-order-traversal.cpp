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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>result;
        int level = 1;
        while(!q.empty())
        {
            int n= q.size();
            vector<int>ans;
            while(n--)
            {
                TreeNode* ele = q.front();
                q.pop();
                ans.push_back(ele->val);
                if(ele->right)q.push(ele->right);
                if(ele->left)q.push(ele->left);
            }
            if(level&1)reverse(ans.begin(),ans.end());
            level++;
            result.push_back(ans);
        }
        return result;
        
    }
};