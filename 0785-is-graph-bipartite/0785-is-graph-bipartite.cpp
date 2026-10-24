
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, int u, char color,vector<char>& coloured) {
        coloured[u]=color;

        for(int v : graph[u])
        {
            if(coloured[v]=='n')
            {
                // char next = ((color=='r')?'g':'r');
                if(!dfs(graph,v,((color=='r')?'g':'r'),coloured)){
                    return false;
                }

            }
            else if(coloured[v]==color)
            {
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<char> coloured(n, 'n');

        for (int i = 0; i < n; i++) {
            if (coloured[i] == 'n') {
                if (!dfs(graph, i, 'r', coloured))
                    return false;
            }
        }

        return true;
    }
};
