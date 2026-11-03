class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(mat[i][j]==0)q.push({i,j});
                else mat[i][j]=-1;
            }
        }
        vector<vector<int>>direction{{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty())
        {
            auto [i,j] = q.front();
            q.pop();
            for(auto dir : direction)
            {
                int new_i = i+dir[0];
                int new_j = j+dir[1];

                if(new_i >=0 && new_i < n && new_j >=0 && new_j < m && mat[new_i][new_j]==-1)
                {
                    q.push({new_i,new_j});
                    mat[new_i][new_j] = mat[i][j]+1;
                }
            }

        }
        return mat;
    }
};