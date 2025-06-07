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

int main() {
    fast;    
    ll t; cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        ll c=0,temp=-1;
        ll ans=0;
        map<ll,set<ll>> mp;
        vi a(n);

        for(auto &i:a) cin>>i;
    
        for(ll x:a) {
            if(mp[x%k].find(x)!=mp[x%k].end()) mp[x%k].erase(x);
            else mp[x%k].insert(x);
        }
    
        for(auto &x:mp){
            ll sz=x.ss.size();
            if(sz%2){
                c++;
                temp=x.ff;
            }
        }
    
        if(c>1){
            eprint(-1)
            continue;
        }
    
        for(auto &x:mp){
            if(x.ff == temp) continue;
            while(x.ss.size()>0){
                ll b=*x.ss.begin();
                x.ss.erase(b);
                if(x.ss.size() == 0) break;
                ll tp = *x.ss.begin();
                x.ss.erase(tp);
                ans+=(tp-b)/k;
            }
        }
    
        if(c){
            vi v;
            for(ll x:mp[temp]) v.push_back(x);
            ll m=v.size();
            if(m==1){
                eprint(ans)
                continue;
            }
            vi p(m,0),s(m,0);
            p[1]=v[1]-v[0];
            for(ll i=3;i<m;i+=2) p[i]=v[i]-v[i-1]+p[i-2];
            s[m-2]=v[m-1]-v[m-2];
            for(ll i=m-4;i>=0;i-=2) s[i]=v[i+1]-v[i]+s[i+2];
            ll ta = 1e18;
            for(ll i=0;i<m;i+=2){
                ll x=0;
                if(i>0) x+=p[i-1];
                if(i+1<m) x+=s[i+1];
                ta=min(ta,x);
            }
            ans+=ta/k;
        }
        eprint(ans)
    }
    
    return 0;
}