#include<bits/stdc++.h>
using namespace std;

#define int int32_t
#define ll long long
#define vl vector<long long>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define foreach(i, a, b, step) for(int i = a; i < b; i += step)

int32_t main() {
    fastio()
    auto solve = [&]() {
        int n, m, k;
        cin >> n >> m >> k;

        // Input original array
        vl v(n);
        foreach(i, 0, n, 1) {
            cin >> v[i];
        }

        // Input range addition operations
        vector<vector<long long>> add(m, vl(3));
        foreach(i, 0, m, 1) {
            cin >> add[i][0] >> add[i][1] >> add[i][2];
        }

        // Input operation queries
        vl opCount(m + 1, 0);
        foreach(i, 0, k, 1) {
            int x, y;
            cin >> x >> y;
            opCount[x - 1]++;
            opCount[y]--;
        }

        // Compute cumulative operation counts
        foreach(i, 1, m, 1) {
            opCount[i] += opCount[i - 1];
        }

        // Apply operations using a difference array
        vl diff(n + 1, 0);
        foreach(i, 0, m, 1) {
            ll l = add[i][0];
            ll r = add[i][1];
            ll increment = add[i][2] * opCount[i];

            diff[l - 1] += increment;
            diff[r] -= increment;
        }

        // Apply cumulative increments to the original array
        foreach(i, 1, n, 1) {
            diff[i] += diff[i - 1];
        }
        foreach(i, 0, n, 1) {
            v[i] += diff[i];
        }

        // Print the final updated array
        foreach(i, 0, n, 1) {
            cout << v[i] << " ";
        }
        cout << endl;
    };

    int t = 1;
    // Uncomment for multiple test cases
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
