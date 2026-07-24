int commonChild(string s1, string s2) {
    int n = s1.length();

    // matrix[i][j] = LCS length of first i characters of s1
    //                and first j characters of s2
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            if (s1[i - 1] == s2[j - 1]) {
                // Characters match
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                // Characters don't match
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }

    return matrix[n][n];
}