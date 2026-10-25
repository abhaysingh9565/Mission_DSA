class Solution {
public:
    vector<vector<string>> ans;
     
    bool isSafe(vector<string> &board,int row,int col,int n)
    {
        for(int i=0 ; i<n ;i++)
        {
            if(board[i][col]=='Q' || board[row][i]=='Q')
            {
                return false;
            }
        }

        for(int i=row,j=col; i>=0&&j>=0;i--,j--)
        {
            if(board[i][j]=='Q')return false;
        }
        for(int i=row,j=col; i>=0&&j<n;i--,j++)
        {
            if(board[i][j]=='Q')return false;
        }

        return true;
    }


    void nQueen(vector<string> &board,int row,int n)
    {
        if(row==n)
        {
            ans.push_back(board);
            return;
        }
        for(int i=0;i<n;i++)
        {
            if(isSafe(board,row,i,n))
            {
                board[row][i]='Q';
                nQueen(board,row+1,n);
                board[row][i]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        nQueen(board,0,n);
        return ans;
        
    }
};