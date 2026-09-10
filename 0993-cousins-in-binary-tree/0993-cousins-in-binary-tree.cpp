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
    bool isCousins(TreeNode* root, int x, int y) {
        pair<int,TreeNode*> X , Y ;
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root,nullptr});
        int level = 1;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                auto [temp,par]=q.front();
                q.pop();
                if(temp->val == x){
                    X.first = level;
                    X.second = par;
                }
                if(temp->val == y){
                    Y.first = level;
                    Y.second = par;
                }
                if(temp->left)q.push({temp->left,temp});
                if(temp->right)q.push({temp->right,temp});

            }
            level++;
        }
        return X.first==Y.first && X.second != Y.second;
        
    }
};