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
        inint (n);
        vi v(n);
        foreach(i,0,n,1)cin>>v[i];
        //code
        if(n==1){
            py;
            return;
        }
        vi pref(n,0),suff(n,0);
        for(int i=0;i<n;i++){
            if(v[i]>=i)pref[i]=1;
            else break;
        }
        // foreach(i,1,n,1) cout<<pref[i]<<" ";
        // out("scvyd");
        rforeach(i,n-1,0,1){
            if(v[i]>=n-i-1)suff[i]=1;
            else break;
        }
        // foreach(i,1,n,1) cout<<suff[i]<<" ";
        // out("scvyd");
        // check 
        foreach(i,0,n,1){
            if(pref[i]==1&&suff[i]==1){
                py;
                return;
            }
        }
        pn;
    };

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}