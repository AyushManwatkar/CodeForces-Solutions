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

int main() {
    fast;
    ll t; cin>>t;
    while(t--){    
        ll n,m; cin>>n>>m;        
        vll x(n),r(n);
        fr(n) cin>>x[i];
        fr(n) cin>>r[i];
        unordered_map<ll,vpll> xInt;
        vll temp(n+m+1);
        temp[n+m]=0;
        fr(n){
            ll xi=x[i],ri=r[i];
            rep1(dx,-ri,ri){
                ll px=xi+dx;
                ll max_y=(ll)sqrt(ri*ri-dx*dx);
                xInt[px].emplace_back(-max_y,max_y);
            }
        }
        ll ans=0;
        for(auto it=xInt.begin();it!=xInt.end();it++){
            ll px=it->ff;
            vpll& itv=it->ss;
            sorta(itv);
            ll cst=itv[0].ff,ced=itv[0].ss;
            ll cnt=0;
            rep(i,1,sz(itv)){
                ll s=itv[i].ff,e=itv[i].ss;
                if(s<=ced+1 || temp[n+m]){
                    ced=max(ced,e);
                }else{
                    cnt+=(ced-cst+1);
                    temp[n+m-3]=cnt;
                    cst=s;
                    ced=e;
                }
            }
            cnt+=(ced-cst+1);
            temp[0]+=cnt-cst+temp[n+m];
            ans+=cnt;
            temp[1]+=ans;
        }
        eprint(ans)
    }
    return 0;
}