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

ll mex(vll& arr,ll l,ll r){
    unordered_set<ll> ele(arr.begin()+l,arr.begin()+r+1);
    ll x=0;
    while(ele.count(x)){
        ++x;
    }
    return x;
}

int main() {
    fast;
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vll a(n);
        fr(n) cin>>a[i];
        vpll ops;
        while(sz(a)>3){
            bool Zero=(count(all(a),0)>0);
            if(Zero){
                ll pos=-1;
                fr(sz(a)){
                    if(a[i]==0){
                        pos=i;
                        break;
                    }
                }
                if(pos==0){
                    ll mexv=mex(a,0,1);
                    ops.pb({1,2});
                    vll newA;
                    newA.pb(mexv);
                    rep(i,2,sz(a)) newA.pb(a[i]);
                    a=newA;
                }else{
                    ll mexv=mex(a,pos-1,pos);
                    ops.pb({pos,pos+1});
                    vll newA;
                    fr(pos-1) newA.pb(a[i]);
                    newA.pb(mexv);
                    rep(i,pos+1,sz(a)) newA.pb(a[i]);
                    a=newA;
                }
            }else{
                ll mexv=mex(a,0,sz(a)-1);
                ops.pb({1,sz(a)});
                vll newA;
                newA.pb(mexv);
                a=newA;
                break;
            }
            if(sz(a)==3){
                ll p=mex(a,0,1);
                if(p!=0 && a[2]!=0){
                    ops.pb({1,2});
                    vll newA;
                    newA.pb(p);
                    newA.pb(a[2]);
                    a=newA;
                }else{
                    ll q=mex(a,1,2);
                    if(a[0]!=0 && q!=0){
                        ops.pb({2,3});
                        vll newA;
                        newA.pb(a[0]);
                        newA.pb(q);
                        a=newA;
                    }else{
                        ops.pb({1,3});
                        ll mexv=mex(a,0,2);
                        vll newA;
                        newA.pb(mexv);
                        a=newA;
                    }
                }
            }
            if(sz(a)==2){
                ll mexv=mex(a,0,1);
                ops.pb({1,2});
                vll newA;
                newA.pb(mexv);
                a=newA;
            }
        }
        eprint(sz(ops))
        for(auto &p:ops){
            sprint(p.ff)
            eprint(p.ss)
        }
    }

    return 0;
}
