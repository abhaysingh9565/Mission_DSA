class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,int start , vector<bool>&visited)
    {
        if(visited[start])return ;

        visited[start]=true;
        for(int i = 0 ; i < isConnected[start].size(); i++)
        {
            if(i!= start && !visited[i] && isConnected[start][i])
            {
                dfs(isConnected,i,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<bool>visited(n,false);
        for(int i = 0 ; i < n ; i++)
        {
            if(!visited[i])
            {
                dfs(isConnected,i,visited);
                ans++;
            }
        }
        return ans;
        
    }
};