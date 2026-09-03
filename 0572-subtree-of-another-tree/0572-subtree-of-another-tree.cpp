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
    bool isSame(TreeNode* p, TreeNode* q)
    {
        if(!p && !q)
        {
            return true;
        }
        if(p && q)
        {
            if(p->val != q->val)return false;

            return isSame(p->left,q->left) && isSame(p->right, q->right);
        }

        return false;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot)
            return true;

        if(!root)
            return false;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                if(q.front()->val == subRoot->val)
                {
                    if(isSame(q.front(),subRoot))
                    return true;
                }
                if(q.front()->left)
                q.push(q.front()->left);
                if(q.front()->right)
                q.push(q.front()->right);

                q.pop();
            }
        }
        return false;
    }
};