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

ll kadane(int start,int end,vl &v){
    ll res=LLONG_MIN;
    ll sum=0;
    for(int i=start;i<end;i++){
        sum+=v[i];
        res=max(res,(ll)sum);
        if(sum<0) sum=0;
    }
    return res;
}

int32_t main()
{
    fastio()
    auto solve = [&] () {
        inint(n);
        vl v(n);
        foreach(i,0,n,1)cin>>v[i];
        // code
        ll yaser= 0;
        foreach(i,0,n,1)yaser+=v[i];
        // cout<<yaser<<endl;
        ll a1=kadane(0,n-1,v);
        ll a2=kadane(1,n,v);
        ll adel= max(a1,a2);
        if(yaser>adel)py;
        else pn;

    };

    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}