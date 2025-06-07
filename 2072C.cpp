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

#define pi (3.14159265358979323846)
#define mod 1000000007
#define inf LLONG_MAX
#define pb push_back
#define pf push_front
#define is insert
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) ((ll)(x).size())
#define max3(a, b, c) max(c, max(a, b))
#define max4(a, b, c, d) max(d, max(c, max(a, b)))
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rfr(n) for(ll i=(n)-1; i>=0; i--)
#define rep1(i,a,b) for(ll i=(a); i<=(b); i++)
#define fr(n) for(ll i=0; i<(n); i++)
#define nesfr(x,y) for(ll i=0; i<(x); i++) for(ll j=0; j<(y); j++)
#define rep(i,a,b) for(ll i=(a); i<(b); i++)
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pll pair<ll, ll>
#define umap unordered_map
#define uset unordered_set
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll, vector<ll>, greater<ll>>
#define print(x) cout << x;
#define sprint(x) cout << x << " ";
#define eprint(x) cout << x << endl;
#define dsprint(ds) for(const auto& x : ds) cout << x << " "; cout << endl;
#define sorta(ds) sort(all(ds))
#define sortd(ds) sort(rall(ds))
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<string> vs;
typedef vector<pll> vpll;
typedef set<ll> sll;
typedef unordered_map<ll, ll> umll;
typedef unordered_set<ll> usll;

ll f(ll m) {
    if(m<=1) return 0u;
    ll mm=m-1;
    ll p=32-__builtin_clz(mm); //position of the highest set bit
    return (1u<<p)-1; //Return 2^p-1
}

int main() {
    fast;
    ll t;cin>>t;
    while(t--){
        ll n,x; cin>>n>>x;
        ll z=0;
        fr(n+1){
            if(i==0) z=0;
            else {
                ll b=f(i);
                if((b & ~x)==0){
                    ll y=(b==x)?i:i+1;
                    if(y<=n){
                        z=i;
                    }
                }
            }    
        }
        set<ll> arr;
        if(z == 0) arr.insert(x);
        else{
            for(ll i = 0; i < z; i++) arr.insert(i);
            ll extra = x & ~f(z);
            if (extra != 0) arr.insert(extra);
        }
        vll ans(all(arr));
        ans.resize(n, (z > 0 ? 0u : x));
        for (auto i : ans) sprint(i);
        cout << endl;
    }
    return 0;
}