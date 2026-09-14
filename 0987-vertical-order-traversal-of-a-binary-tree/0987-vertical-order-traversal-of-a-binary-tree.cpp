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
// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         map<int,vector<int>>mp;
//         queue<pair<TreeNode*,int>>q;
//         vector<vector<int>>ans;
//         if(!root)return ans;
//         q.push({root,0});
//         while(!q.empty())
//         {
//             TreeNode* num = q.front().first;
//             int hd = q.front().second;
//             q.pop();
//             mp[hd].push_back(num->val);
//             if(num->right)q.push({num->right,hd+1});
//             if(num->left)q.push({num->left,hd-1});

//         }
//         for(auto x : mp)
//         {
//             vector<int>temp = x.second;
//             // sort(temp.begin(),temp.end());
//             ans.push_back(temp);
//         }
//         return ans;
//     }
// };

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        map<int, map<int, vector<int>>> mp;

        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty()) {

            auto front = q.front();
            q.pop();

            TreeNode* node = front.first;
            int row = front.second.first;
            int col = front.second.second;

            mp[col][row].push_back(node->val);

            if (node->left)
                q.push({node->left, {row + 1, col - 1}});

            if (node->right)
                q.push({node->right, {row + 1, col + 1}});
        }

        vector<vector<int>> ans;

        for (auto &col : mp) {

            vector<int> temp;

            for (auto &row : col.second) {
                sort(row.second.begin(),row.second.end());
                for (int val : row.second)
                    temp.push_back(val);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};