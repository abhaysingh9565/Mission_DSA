// class Solution {
// public:
//     vector<string> createGrid(int m, int n) {
//         vector<string>grid(m,string(n,'#'));
//         for(int i = 0; i < m ; i++)
//         {
//             grid[i][n-1]='.';
//         }
//         for(int i = 0 ; i < n ; i++)
//         {
//             grid[0][i]='.';
//         }
//         return grid;
//     }
// };
class Solution {
public:
    vector<string> createGrid(int n, int m) {
        vector<string> grid(n, string(m, '#'));
        for (int i = 0; i < m; i++)
            grid[0][i] = '.';
        for (int i = 0; i < n; i++)
            grid[i][m - 1] = '.';
        return grid;
    }
};