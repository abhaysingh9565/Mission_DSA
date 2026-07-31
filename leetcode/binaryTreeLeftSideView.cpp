#include<iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        queue<Node*>q;
        vector<int>ans;
        if(!root)return {};
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            Node* num;
            while(n--)
            {
                num = q.front();
                q.pop();
                if(num->right)q.push(num->right);
                if(num->left)q.push(num->left);
            }
            ans.push_back(num->data);
        }
        return ans;
        
    }
        
};