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
 vector<string> names = {
            "Alice", "Bob", "Charlie", "Diana", "Ethan", "Fiona", "George", "Hannah", 
            "Isaac", "Julia", "Kevin", "Laura", "Michael", "Nina", "Oliver", "Penelope", 
            "Quincy", "Rachel", "Samuel", "Tina", "Ulysses", "Vanessa", "William", "Xena", 
            "Yvonne", "Zachary", "Amelia", "Benjamin", "Catherine", "Daniel", "Elena", 
            "Frederick", "Gabriella", "Harold", "Isabella", "James", "Katherine", "Leonard", 
            "Margaret", "Nathan", "Ophelia", "Patrick", "Quinn", "Rebecca", "Sebastian", 
            "Thomas", "Ursula", "Victor", "Wendy", "Xander", "Yvette"
        };

int32_t main() {
    fastio();

    // Solve function
    auto solve = [&]() {
        int n, k;
        cin >> n >> k;

        vector<string> v(n - k + 1); // Input for "YES" or "NO"
        for (int i = 0; i < n - k + 1; i++) {
            cin >> v[i];
        }

        vector<string> res;
        for (int i = 0; i < n; i++) {
            res.push_back(names[i]); // Initialize with the first 'n' names
        }

        int i = k - 1, j = 0, ind = 0; // Indices for traversal
        while (i < n && ind < v.size()) {
            if (v[ind] == "NO") {
                res[i] = res[j]; // Copy name from index `i` to `j`
            }
            i++;
            ind++;
            j++;
        }

        // Output the result
        for (int i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << endl;
    };

    // Number of test cases
    int t=1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
