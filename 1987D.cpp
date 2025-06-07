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

ll dp[5001][5001];
ll ct[5001];

ll r(ll x,ll y);

int main()
{
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        vi a(n);
        rep1(i,0,n) fill_n(dp[i],n+1,-1);
        fr(n){ 
            ll x; cin>>x;
            a[i]=x;
            ct[x]++; 
        }
        sort(all(a));
        // bool turn=true;
        // ll alice=0,bob=0,c=0;
        // fr(n){
        //     if(turn){
        //         if(a[i]>alice){
        //             c++;
        //             alice=a[i];
        //             turn=false;
        //         }
        //     }else turn=true;
        // }
        ll ans=n;
        rfr(n+1) if(!(r(n,i)==-2)) ans=i;
        eprint(ans)
        fill_n(ct,n+1,0ll);
        a.clear();
        a.shrink_to_fit();
    }
}

ll r(ll x,ll y){
    if(y<0) return -2; 
        if(x==0) return (y==0)?0:-2; 

    if(dp[x][y]!=-1) return dp[x][y];

    if(!ct[x]){
        dp[x][y]=r(x-1,y);
    }else{
        dp[x][y]=r(x-1,y-1);
    }

    ll notval=r(x-1,y);

    if (!(notval==-2) && !(notval+ct[x]>y)){
        if(!(dp[x][y]!=-2) || !(notval+ct[x]>=dp[x][y])){
            dp[x][y] =notval+ct[x];
        }
    }

    return dp[x][y];
}