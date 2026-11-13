class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        queue<pair<int,pair<int,int>>>q;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({0,{i,j}});
                }
                else if(grid[i][j]==1)count++;
            }
        }
        int time =0;
        vector<vector<int>>direction{{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty())
        {
            // int i = q.front().second.first;
            // int j = q.front().second.second;
            // int time = q.front().first;
            // q.pop();
            // if(count==0)return time;
            auto it = q.front();
            q.pop();

            int t = it.first;
            int i = it.second.first;
            int j = it.second.second;

            time = max(time, t);
            for(auto &dir : direction)
            {
                int new_i = i+dir[0];
                int new_j = j+dir[1];
                if(new_i >=0 && new_i < n && new_j >=0 && new_j < m && grid[new_i][new_j]==1)
                {
                    q.push({time+1,{new_i,new_j}});
                    count--;
                    grid[new_i][new_j] = 2;
                }
            }
        }
        return count == 0 ? time : -1;
    }
};