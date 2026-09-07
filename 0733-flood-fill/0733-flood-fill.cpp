class Solution {
public:
    void dfs(int i , int j , vector<vector<bool>>& vis, vector<vector<int>>& image,int color,int n , int m,int real)
    {
        if(i<0 || j < 0 || i>=n || j>=m || vis[i][j] || image[i][j]!=real)
        {
            return ;
        }
        vis[i][j]=true;
        image[i][j]=color;
        dfs(i+1, j , vis,image,color,n,m,real);
        dfs(i-1, j , vis,image,color,n,m,real);
        dfs(i, j+1 , vis,image,color,n,m,real);
        dfs(i, j-1 , vis,image,color,n,m,real);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n= image.size();
        int m = image[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        dfs(sr,sc,vis,image,color,n,m,image[sr][sc]);
        return image;
    }
};