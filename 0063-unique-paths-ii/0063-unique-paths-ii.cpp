class Solution {
public:
    int countPaths(int row , int col ,vector<vector<int>>& obstacleGrid)
    {
        if(row<0 || col<0 || obstacleGrid[row][col]==-1)return 0;
        if(row == 0 && col == 0)
        {
            return 1;
        }
        if(obstacleGrid[row][col]!=0)
        {
            return obstacleGrid[row][col];
        }
        obstacleGrid[row][col] += countPaths(row,col-1,obstacleGrid);
        obstacleGrid[row][col] += countPaths(row-1,col,obstacleGrid);

        return obstacleGrid[row][col];

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)return 0;
        for(int i = 0 ; i< m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if(obstacleGrid[i][j]==1)obstacleGrid[i][j]=-1;
            }
        }
        return countPaths(m-1,n-1,obstacleGrid);
        
    }
};