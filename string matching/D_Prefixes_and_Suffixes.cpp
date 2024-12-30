#include <iostream>
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

// Macros
#define IOtext freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define PI (3.141592653589)
#define M 1000000007
#define pb push_back
#define f first
#define s second
#define foreach(i, j, k, in) for (int i = j; i < k; i += in)
#define rforeach(i, j, k, in) for (int i = j; i >= k; i -= in)
#define rep(i, j) foreach(i, 0, j, 1)
#define rrep(i, j) rforeach(i, j, 0, 1)
#define set_bits(x) __builtin_popcountll(x)
#define zero_bits(x) __builtin_ctzll(x)
#define Num_of_Digits(n) ((int)log10(n) + 1)
#define inint(x) int x; cin >> x;
#define inll(x) long long int x; cin >> x;
#define instr(x) string x; cin >> x;
#define all(x) x.begin(), x.end()
#define out(x) cout << x << endl;
#define py cout << "YES" << endl
#define pn cout << "NO" << endl
#define pm cout << "-1" << endl
#define ps(x, y) fixed << setprecision(y) << x

// Typedef
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<char, int> mci;
typedef set<int> st;

void computeZArray(string& s, vi& z) {
    int n = s.size();
    int l = 0, r = 0;
    foreach(i, 1, n, 1) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

int32_t main() {
    fastio();
    string s;
    cin >> s;
    int n = s.size();

    vi z(n, 0);
    computeZArray(s,z);
    z[0]=n;

    // counting how many suffix and prefix are present  

    vector<bool>count(n+1,false); 
    for(int i=0;i<n;i++){
        if(i+z[i]==n)count[z[i]]=true;
    }
    // count 
    int c=0;
    for(auto i: count) if(i) c++;
    cout<<c<<endl;

    // -----------------------------------------
    // total frequency 
    vi freq(n+1,0);
    for(int i=0;i<n;i++){
        if(z[i]!=0){
            freq[z[i]]++;
        }
    }
    // suffix sum
    for(int i=n-1;i>=0;i--){
        freq[i]+=freq[i+1];
    }
    // output it 
    for(int i=1;i<freq.size();i++){
        if(count[i])cout<<i<<" "<<freq[i]<<endl;
    }





    return 0;
}
