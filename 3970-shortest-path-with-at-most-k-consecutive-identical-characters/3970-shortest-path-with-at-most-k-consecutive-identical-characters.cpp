
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        
        vector<vector<pair<int,int>>> adj(n);

        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
        }

        // dist[node][count]
        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        // {distance, node, consecutive count}
        priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        > pq;

        // Starting node has a consecutive count of 1
        dist[0][1] = 0;
        pq.push({0, 0, 1});

        while(!pq.empty()) {

            auto [d, u, cnt] = pq.top();
            pq.pop();

            if(d != dist[u][cnt]) continue;

            // First destination state popped is optimal
            if(u == n - 1) return (int)d;

            for(auto [v, w] : adj[u]) {

                int newCnt = (labels[u] == labels[v]) ? cnt + 1 : 1;

                if(newCnt > k) continue;

                long long newDist = d + w;

                if(newDist < dist[v][newCnt]) {
                    dist[v][newCnt] = newDist;
                    pq.push({newDist, v, newCnt});
                }
            }
        }

        return -1;
    }
};
