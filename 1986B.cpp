#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native,avx,avx2,fma")
#pragma GCC optimize("fast-math")

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
#define rfr(n) for(int i=n-1;i>=0;i--)
#define rep1(i,a,b) for(long long i=a;i<=b;i++)
#define fr(n) for(long long i=0;i<n;i++)
#define nesfr(x,y) for(long long i=0;i<x;i++) for(long long j=0;j<y;j++) cin >> a[i][j];
#define rep(i,a,b) for(long long i=a;i<b;i++)
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

void algo(vector<vector<ll>>& a, ll n, ll m) {
    rep(i,0,n){
        rep(j,0,m){
            ll maxi=0;
            ll c=1;
            if(i-1>=0) maxi=max(maxi,a[i-1][j]);
            if(j-1>=0) maxi=max(maxi,a[i][j-1]);
            if(i+1<n) maxi=max(maxi,a[i+1][j]);
            if(j+1<m) maxi=max(maxi,a[i][j+1]);
            if(i-1>=0 && a[i][j]<=a[i-1][j]) c=0;
            if(j-1>=0 && a[i][j]<=a[i][j-1]) c = 0;
            if(i+1<n && a[i][j]<=a[i+1][j]) c = 0;
            if(j+1<m && a[i][j]<=a[i][j+1]) c = 0;
            if(c==1) a[i][j]=maxi;
        }
    }
}

int main() {
    fast;
    ll t; cin>>t;
    while(t--){
        ll n,m; cin>>n>>m;
        vector<vi> a(n,vi (m));
        nesfr(n,m);

        algo(a, n, m);

        rep(i,0,n){
            rep(j,0,m) sprint(a[i][j]);
            cout << endl;
        }
    }

    return 0;
}
