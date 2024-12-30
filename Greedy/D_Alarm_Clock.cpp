#include <bits/stdc++.h>
using namespace std;

#define int long long
#define vi vector<int>
#define all(v) v.begin(), v.end()
#define foreach(i, a, b, step) for (int i = a; i < b; i += step)
#define fastio() ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define out(x) cout << x << '\n';

// Function to handle the logic for turning off alarms
int getMin(int n, int m, int k, vi &v) {
    set<int> st; 
    int res = 0; 
    foreach(i, 0, n, 1) {
        int x = v[i];

        // Remove alarms that are too old
        while (!st.empty() && *st.begin() < x - m + 1) {
            st.erase(st.begin());
        }
        if ((int)st.size() < k - 1) {
            st.insert(x); 
        } else {
            res++; 
        }
    }

    return res;
}

int32_t main() {
    fastio();
    auto solve = [&]() {
        int n, m, k;
        cin >> n >> m >> k;
        vi v(n);
        foreach(i, 0, n, 1) cin >> v[i];
        sort(all(v));
        int result = getMin(n, m, k, v);
        out(result);
    };

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
