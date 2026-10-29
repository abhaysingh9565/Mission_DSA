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
    void inorder(TreeNode* root, vector<int>&arr)
    {
        if(root)
        {
            inorder(root->left,arr);
            arr.push_back(root->val);
            inorder(root->right,arr);
        }
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>ans;
        vector<int>s1,s2;
        inorder(root1,s1);
        inorder(root2,s2);
        int i = 0 , j = 0;
        while(i< s1.size() && j < s2.size())
        {
            if(s1[i]<s2[j])
            {
                ans.push_back(s1[i++]);
            }
            else ans.push_back(s2[j++]);
        }
        while(j<s2.size())
        {
            ans.push_back(s2[j++]);
        }
        while(i< s1.size())
        {
            ans.push_back(s1[i++]);
        }
        return ans;
    }
};