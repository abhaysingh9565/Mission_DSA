class Solution {
public:
    int countPaths(int row , int col , vector<vector<int>> &dp,vector<vector<int>>& obstacleGrid)
    {
        if(row<0 || col<0 || obstacleGrid[row][col]==1)return 0;
        if(row == 0 && col == 0)
        {
            return 1;
        }
        if(dp[row][col]!=0)
        {
            return dp[row][col];
        }
        dp[row][col] += countPaths(row,col-1,dp,obstacleGrid);
        dp[row][col] += countPaths(row-1,col,dp,obstacleGrid);

        return dp[row][col];

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1)return 0;
        vector<vector<int>> dp(m, vector<int>(n,0));
        return countPaths(m-1,n-1,dp,obstacleGrid);
        
    }
};