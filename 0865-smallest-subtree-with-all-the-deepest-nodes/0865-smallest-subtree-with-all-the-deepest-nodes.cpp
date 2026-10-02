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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q)return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right , p , q);

        if(left && right)return root;

        return left ? left : right ? right : nullptr;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<TreeNode*>arr;
        while(!q.empty())
        {
            int n = q.size();
            arr.clear();
            for(int i = 0 ; i < n ; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                arr.push_back(temp);
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        TreeNode* ans = arr[0];
        for(int i = 1 ; i<arr.size(); i++)
        {
            ans = lowestCommonAncestor(root , ans , arr[i]);
        }
        return ans;
    }
};