#pragma GCC optimize("Ofast")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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
#define rfr(n) for(int i=n-1;i>=0;i--)
#define rep1(i,a,b) for(long long i=a;i<=b;i++)
#define fr(n) for(long long i=0;i<n;i++)
#define nesfr(x,y) for(long long i=0;i<x;i++)for(long long j=0;j<y;j++)
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

void calculateCommonReviews(ll n, const vector<ll>& a, const vector<ll>& b, ll& posi, ll& neg) {
    posi=0,neg=0;
    fr(n){
        if(a[i]==b[i] && a[i]==-1) neg--;
        else if (a[i]==b[i] && a[i]==1) posi++;
    }
}

void calculateAB(ll n,const vector<ll>& a,const vector<ll>& b,ll& a_rate,ll& b_rate){
    a_rate=0,b_rate=0;
    fr(n){
        if (a[i]==b[i]) continue;
        if (a[i]>b[i]) a_rate += a[i];
        else b_rate += b[i];
    }
    if(a_rate>b_rate) swap(a_rate,b_rate);
}

ll maxCompanyRating(ll n,const vector<ll>& a,const vector<ll>& b){
    ll posi,neg;
    calculateCommonReviews(n,a,b,posi,neg);
    ll a_rate,b_rate;
    calculateAB(n,a,b,a_rate,b_rate);
    ll C=posi;
    ll x=min(b_rate-a_rate,C);
    a_rate+=x; C-=x; x=C/2; C=C-x;
    a_rate+=max(C,x);
    b_rate+=min(C,x);
    if(a_rate>b_rate) swap(a_rate,b_rate);
    C=neg;
    x=max(a_rate-b_rate,C);
    b_rate+=x; C-=x; x=C/2; C=C-x;
    a_rate+=max(x,C);
    b_rate+=min(x,C);
    return min(a_rate,b_rate);
}

int main() {
    fast;
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vi a(n),b(n);
        fr(n) cin>>a[i];
        fr(n) cin >> b[i];
        ll maxRating = maxCompanyRating(n,a,b);

        eprint(maxRating)
    }

    return 0;
}