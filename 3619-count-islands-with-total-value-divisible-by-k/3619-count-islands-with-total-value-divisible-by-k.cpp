class Solution {
private:
    void dfs(vector<vector<int>>& grid,int i , int j , long &sum, vector<vector<bool>>&visited)
    {
        if( i<0 || i >= m || j < 0 || j >=n || grid[i][j]==0 || visited[i][j]==true)
        {
            return;
        }
        visited[i][j]=true;
        sum += grid[i][j];
        dfs(grid,i+1,j,sum,visited);
        dfs(grid,i-1,j,sum,visited);
        dfs(grid,i,j+1,sum,visited);
        dfs(grid,i,j-1,sum,visited);
    }
public:
    int n , m;
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int ans = 0;
        for(int i = 0 ; i < m ;i++)
        {
            for(int j =0 ; j < n ; j++)
            {
                if(grid[i][j]!=0 && visited[i][j]==false)
                {
                    long sum = 0;
                    dfs(grid,i,j,sum,visited);
                    if(sum%k==0)ans++;
                }
            }
        }
        return ans;
        
    }
};