#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define vll vector<ll>
#define pb push_back

void solve() {
    set<ll> az;
    set<ll> z;
    string s;
    cin >> s;
    map<ll, vll> a;
    ll count = -1;

    for (ll i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            if (az.empty()) {
                count++;
                a[count].pb(i + 1);
                z.insert(count);
            } else {
                ll num = *az.begin();
                a[num].pb(i + 1);
                az.erase(num);
                z.insert(num);
            }
        }
        if (s[i] == '1') {
            if (z.empty()) {
                cout << -1 << endl;
                return;
            } else {
                ll num = *z.begin();
                a[num].pb(i + 1);
                z.erase(num);
                az.insert(num);
            }
        }
    }

    if (!az.empty()) {
        cout << -1 << endl;
        return;
    }

    cout << count + 1 << "\n";
    for (ll i = 0; i <= count; i++) {
        cout << a[i].size() << " ";
        for (ll j = 0; j < a[i].size(); j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    fastio();
    solve();
    return 0;
}
