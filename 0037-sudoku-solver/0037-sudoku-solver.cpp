class Solution {
public:
    bool isSafe(vector<vector<char>>&board,int row,int col,char n)
    {
        for(int i=0 ; i<9 ;i++)
        {
            if((i!=row && board[i][col]==n) || (i!=col && board[row][i]==n))
            {
                return false;
            }
        }
        for(int i = row/3*3;i<row/3*3+3;i++)
        {
            for(int j = col/3*3;j<col/3*3+3;j++)
            {
               if(board[i][j] == n){
                    return false;
                }
            }
        }

        return true;
    }
    bool solve(vector<vector<char>>& board,int row,int col)
    {
        if(col == 9)
        {
            row=row+1;
            col=0;
        }
        if(row==9)return true;
        if(board[row][col]!='.')
        {
            return solve(board,row,col+1);
        }
        for(int j = 1 ; j <= 9 ; j++)
        {
           if(isSafe(board,row,col,j+'0'))
           {
                board[row][col]=j+'0';
                if(solve(board,row,col+1))
                return true;
                board[row][col]='.';
            }
        }
        return false;


    }
    void solveSudoku(vector<vector<char>>& board) {
        bool ans = solve(board,0,0);
        
    }
};