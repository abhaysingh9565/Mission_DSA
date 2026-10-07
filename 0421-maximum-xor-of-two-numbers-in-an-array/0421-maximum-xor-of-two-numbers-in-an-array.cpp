class TrieNode{
    public:
    TrieNode* left,*right;
    TrieNode()
    {
        left=nullptr;
        right=nullptr;
    }
};

class Solution {
    void insert(TrieNode* root , int num)
    {
        TrieNode* curr = root;
        for(int i = 31 ; i>=0 ; i--)
        {
            int bit = (num>>i)&1;
            if(bit==0)
            {
                if(!curr->left)
                {
                    curr->left = new TrieNode();
                }
                curr = curr->left;
            }
            else{
                if(!curr->right)
                {
                    curr->right = new TrieNode();
                }
                curr = curr->right;
            }
        }
    }

    int XOR(TrieNode* root , int num)
    {
        TrieNode* curr = root;
        int ans=0;
        for(int i = 31 ; i>=0 ; i--)
        {
            int bit = (num>>i)&1;
            if(bit)
            {
                if(curr->left)
                {
                  curr = curr->left;
                  ans+= pow(2,i);
                }
                else
                   curr = curr->right;
            }
            else{
                if(curr->right)
                {
                    curr = curr->right;
                    ans+= pow(2,i);
                }
                else
                curr = curr->left;
            }
        }
        return ans;
    }
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        int ans = 0;
        for(int x : nums)
        {
            insert(root,x);
        }
        for(int x : nums)
        {
            ans = max(ans,XOR(root,x));
        }
        return ans;

    }
};