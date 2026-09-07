class Solution {
public:
    vector<vector<int>>result;
    vector<int>path;
    void dfs(int src , int des , vector<vector<int>>& graph)
    {
        if(src == des)
        {
            result.push_back(path);
            return;
        }
        for(int x : graph[src])
        {
            path.push_back(x);
            dfs(x,des,graph);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        path.push_back(0);
        dfs(0,n-1,graph);
        return result;
    }
};