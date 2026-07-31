#include<iostream>
using namespace std;
//Definition for a binary tree node.
 struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        if(!root)return {};

        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            TreeNode* num ;
            while(n--)
            {
                num = q.front();
                q.pop();
                if(num->left)q.push(num->left);
                if(num->right)q.push(num->right);
            }
            ans.push_back(num->val);
        }
        return ans;
    }
};