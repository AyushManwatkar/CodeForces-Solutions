#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define pi (3.141592653589)
#define mod 1000000007
#define pb push_back
#define is insert
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rfr(n) for(ll i=n-1;i>=0;i--)
#define rep1(i,a,b) for(ll i=a;i<=b;i++)
#define fr(n) for(ll i=0;i<n;i++)
#define nesfr(x,y) for(ll i=0;i<x;i++)for(ll j=0;j<y;j++)
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define pll pair<ll,ll>
#define print(x) cout<<x;
#define sprint(x) cout<<x<<" ";
#define eprint(x) cout<<x<<endl;
#define dsprint(ds) for(const auto& x:ds)
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<pll> vpll;
#define matrix(m,n,x)  vector<vi> m(n,vi(x));

bool isequal(vector<vector<ll>>& a,vector<vector<ll>>& b,ll n,ll m){
    fr(n) if (a[i][0] != b[i][0]) return false;
    fr(m) if (a[0][i] != b[0][i]) return false;
    return true;
}

void solve(vector<vector<ll>>& a, const vector<vector<ll>>& b,ll n,ll m) {
    for(ll i=n-1;i>=1;i--){
        for(ll j=m-1;j>=1;j--){
            if(a[i][j]!=b[i][j]){
                ll d=(b[i][j]-a[i][j]+3)%3;
                a[i][j]=b[i][j];
                a[i-1][j]=(a[i-1][j]+2*d)%3;   // Basic check
                a[i][j-1]=(a[i][j-1]+2*d)%3;
                a[i-1][j-1]=(a[i-1][j-1]+d)%3;
            }
        }
    }
}

int main() {
    fast
    ll t; cin>>t;
    while(t--){
        ll n,m; cin>>n>>m;
        matrix(a,n,m);
        matrix(b,n,m);
        nesfr(n,m){
            char value; cin>>value;
            a[i][j]=value-'0';
        }
        nesfr(n,m){
            char value; cin>>value;
            b[i][j]=value-'0';
        }

        solve(a,b,n,m);

        bool ans=isequal(a,b,n,m);
        eprint((ans?"YES":"NO"))
    }

    return 0;
}
