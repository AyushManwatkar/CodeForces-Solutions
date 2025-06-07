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

int main(){
    ll t; cin>>t;
    while(t--){
        ll l,r; cin>>l>>r;
        ll ans=0;
        
        ll nl=l+1,cl=l;   // l
        while(cl>0){
            cl/=3;
            ans+=2;
        }
        // ans+=cl/3;

        while(nl>0){    //nextleft(nl)
            nl/=3;
            ans+=1;
        }

        // Calculate operations : range [l+2,r]
        rep1(i,l+2,r){
            ll x=i;
            while(x>0){
                x/=3;
                ans+=1;
            }
        }
        
        eprint(ans);
    }

    return 0;
}