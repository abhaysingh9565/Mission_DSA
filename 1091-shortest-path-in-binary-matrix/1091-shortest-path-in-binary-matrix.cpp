
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Starting or ending cell is blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        // 8 possible directions
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        queue<pair<int, pair<int, int>>> q;

        q.push({1, {0, 0}});
        grid[0][0] = 1; // Mark visited

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int dist = it.first;
            int x = it.second.first;
            int y = it.second.second;

            // Destination reached
            if (x == n-1 && y == n-1)
                return dist;

            // Explore all 8 directions
            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && ny >= 0 &&
                    nx < n && ny < n &&
                    grid[nx][ny] == 0) {

                    grid[nx][ny] = 1; // Mark visited
                    q.push({dist + 1, {nx, ny}});
                }
            }
        }

        return -1;
    }
};
