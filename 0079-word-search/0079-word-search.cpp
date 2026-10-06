class Solution {
    bool dfs(vector<vector<char>>& board, string word,int index,int i , int j)
    {
        if(index>=word.size())
        {
            return true;
        }
        if(i<0 || i >= board.size() || j<0 || j >= board[0].size() || board[i][j]!=word[index])
        {
            return false;
        }

        char ch = board[i][j];
        board[i][j]='*';
        bool ans  = dfs(board,word,index+1,i+1,j) || dfs(board,word,index+1,i,j+1) || dfs(board,word,index+1,i,j-1)|| dfs(board,word,index+1,i-1,j);

        board[i][j]=ch;
        return ans;


    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0 ; i < board.size() ; i++)
        {
            for(int j = 0 ; j < board[0].size(); j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(board,word,0,i,j))return true;
                }
            }
        }
        return false;
    }
};