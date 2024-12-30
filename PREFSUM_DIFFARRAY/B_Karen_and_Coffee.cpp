#include<iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

//Macros
#define IOtext freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
#define PI (3.141592653589)
#define M 1000000007
#define pb push_back
#define f first
#define s second
#define foreach(i, j, k, in) for(int i=j;i<k;i+=in)
#define rforeach(i, j, k, in) for(int i=j;i>=k;i-=in)
#define rep(i,j) foreach(i,0,j,1)
#define rrep(i,j) rforeach(i,j,0,1)
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define inint(x) int x; cin>>x;
#define inll(x) long long int x; cin>>x;
#define instr(x) string x; cin>>x;
#define all(x) x.begin(), x.end()
#define out(x) cout << x << endl;
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define pm cout<<"-1"<<endl
#define ps(x,y) fixed<<setprecision(y)<<x

//Typedef
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int,int> mii;
typedef map<ll,ll> mll;
typedef map<char,int> mci;
typedef set<int> st;

int32_t main()
{
    fastio()
    auto solve = [&] () {
        ll n, k, q;
        cin >> n >> k >> q;

        vpi v(n);
        ll mini = LLONG_MAX, maxi = LLONG_MIN;

        foreach(i, 0, n, 1) {
            ll a, b;
            cin >> a >> b;
            mini = min(mini, a);
            maxi = max(maxi, b);
            v[i] = {a, b};
        }

        vpi query(q);
        foreach(i, 0, q, 1) {
            ll a, b;
            cin >> a >> b;
            query[i] = {a, b};
        }

        ll size = maxi - mini + 2;
        vl diff(size, 0);

        // Update difference array
        for (int i = 0; i < n; i++) {
            int a = v[i].first;
            int b = v[i].second;
            diff[a - mini]++;
            diff[b - mini + 1]--;
        }

        // Prefix sum for difference array
        for (int i = 1; i < diff.size(); i++) {
            diff[i] += diff[i - 1];
        }

        // Prefix array for range queries
        vl pref(size, 0);
        for (int i = 1; i < size; i++) {
            if (diff[i - 1] >= k) diff[i - 1] = 1;
            else diff[i - 1] = 0;
            pref[i] = pref[i - 1] + diff[i - 1];
        }

        // Process range queries
        for (int i = 0; i < q; i++) {
            int left = max(query[i].first, (int)mini);
            int right = min(query[i].second, (int)maxi);

            if (left > right) {
                cout << 0 << endl;  // Invalid range
                continue;
            }

            cout << pref[right - mini + 1] - pref[left - mini] << endl;
        }
    };

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
