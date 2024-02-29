#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int caseNum = 1; caseNum <= t; ++caseNum) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        // Calculate prefix XOR array
        vector<int> xorPrefix(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            xorPrefix[i] = xorPrefix[i - 1] ^ a[i - 1];
        }

        cout << "Case " << caseNum << ":\n";
        for (int i = 0; i < q; ++i) {
            int l, r;
            cin >> l >> r;

            // Calculate maximum XOR value in the given subsegment
            int maxXOR = xorPrefix[r] ^ xorPrefix[l - 1];

            // Output the minimum non-negative integer that satisfies the condition
            cout << maxXOR << "\n";
        }
    }

    return 0;
}
