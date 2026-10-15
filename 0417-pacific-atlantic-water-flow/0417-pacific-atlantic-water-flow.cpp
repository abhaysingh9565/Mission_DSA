class Solution {
public:
    int n , m;
    void dfs(vector<vector<int>>& heights,int i , int j , int prev,vector<vector<bool>>&visited)
    {
        if(i<0 || j<0 || i >=n || j >=m ||visited[i][j]|| heights[i][j]<prev)return;

        visited[i][j]= true;

        dfs(heights,i+1,j,heights[i][j],visited);
        dfs(heights,i-1,j,heights[i][j],visited);
        dfs(heights,i,j+1,heights[i][j],visited);
        dfs(heights,i,j-1,heights[i][j],visited);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>>ans;
        vector<vector<bool>>pacific(n,vector<bool>(m,false));
        vector<vector<bool>>atlantic(n,vector<bool>(m,false));

        for(int i = 0 ; i < m ; i++)
        {
            dfs(heights,0,i,heights[0][i],pacific);
        }
        for(int i = 0 ; i < n ; i++)
        {
            dfs(heights,i,0,heights[i][0],pacific);
        }
        for(int i = 0 ; i < m ; i++)
        {
            dfs(heights,n-1,i,heights[n-1][i],atlantic);
        }
        for(int i = 0 ; i < n ; i++)
        {
            dfs(heights,i,m-1,heights[i][m-1],atlantic);
        }

        for(int i = 0 ; i < n ;i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(pacific[i][j]==true && atlantic[i][j]==true)
                ans.push_back({i,j});
            }
        }

        return ans;
    }
};


