class Solution {
public:
    vector<vector<int>>result;
    vector<int>path;
    void dfs(int src , int des , vector<vector<int>>& graph)
    {
        if(src == des)
        {
            path.push_back(src);
            result.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(src);
        for(int x : graph[src])
        {
            dfs(x,des,graph);
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        dfs(0,n-1,graph);
        return result;
    }
};