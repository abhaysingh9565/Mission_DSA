string larrysArray(vector<int> A) {
    int n = A.size();
    int inversions = 0;

    // Count inversions
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                inversions++;
            }
        }
    }

    return (inversions % 2 == 0) ? "YES" : "NO";
}