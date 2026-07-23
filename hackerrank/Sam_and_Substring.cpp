int substrings(string n) {
    const int MOD = 1e9 + 7;
    long long total = 0;
    long long prev = 0;

    for (int i = 0; i < n.length(); ++i) {
        int digit = n[i] - '0';
        prev = (prev * 10 + digit * (i + 1)) % MOD;
        total = (total + prev) % MOD;
    }

    return static_cast<int>(total);
}