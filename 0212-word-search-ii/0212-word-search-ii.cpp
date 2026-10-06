class TrieNode{
    public:
    TrieNode* children[26];
    bool isEnd ;
    string word ="";
    TrieNode()
    {
        for(int i = 0 ; i < 26 ; i++)
        {
            children[i]=nullptr;
        }
        isEnd = false;
    }
};

class Solution {

    vector<string>result;
    void insert(TrieNode* root ,string &word) {
        TrieNode* curr = root;
        for(char c : word)
        {
            if(curr->children[c-'a']==nullptr)
            {
                TrieNode* node = new TrieNode();
                curr->children[c-'a'] = node;
            }
            curr = curr->children[c-'a'];
        }
        curr->word = word;
        curr->isEnd = true;
    }

    void find(vector<vector<char>>& board,int i , int j , TrieNode* root)
    {
        if(i<0 || i >= board.size() || j<0 || j >= board[0].size())
            return ;

        if(board[i][j]=='*' || root->children[board[i][j]-'a']==NULL)
            return;

        root = root->children[board[i][j]-'a'];
        if(root->isEnd)
        {
            result.push_back(root->word);
            root->isEnd = false;
        }

        char ch = board[i][j];
        board[i][j]='*';

        find(board,i+1,j,root);
        find(board,i-1,j,root);
        find(board,i,j+1,root);
        find(board,i,j-1,root);

        board[i][j]=ch;

    }

public:

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string s : words)
        {
            insert(root,s);
        }

        for(int i = 0 ; i < board.size() ;i++)
        {
            for(int j = 0 ; j < board[0].size(); j++)
            {
                if(root->children[board[i][j]-'a'])
                {
                    find(board,i,j,root);
                }
            }
        }
        return result;
    }
};