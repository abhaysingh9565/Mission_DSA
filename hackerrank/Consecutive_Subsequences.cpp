#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {

        int N, K;
        cin >> N >> K;

        vector<int> arr(N);

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        long long prefixSum = 0;
        long long count = 0;

        unordered_map<int, int> modCount;

        modCount[0] = 1;

        for (int i = 0; i < N; i++) {

            prefixSum += arr[i];

            int mod = ((prefixSum % K) + K) % K;

            count += modCount[mod];

            modCount[mod]++;
        }

        cout << count << endl;
    }

    return 0;
}