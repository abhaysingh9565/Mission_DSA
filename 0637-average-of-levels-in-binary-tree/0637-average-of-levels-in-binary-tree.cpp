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
    vector<double> averageOfLevels(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<double>result;
        while(!q.empty())
        {
            int n= q.size();
            double sum = 0;
            int count = 0;
            while(n--)
            {
                TreeNode* ele = q.front();
                q.pop();
                sum+=(ele->val);
                count++;
                if(ele->left)q.push(ele->left);
                if(ele->right)q.push(ele->right);
            }
            result.push_back(sum/count);
        }
        return result;
        
    }
};