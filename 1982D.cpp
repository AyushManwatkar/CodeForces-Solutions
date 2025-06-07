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

int main()
{
    fast;    
    ll t; cin>>t;
    while(t--){
        ll n,m,k; cin>>n>>m>>k;
        ll a[n+1][m+1], tp[n+1][m+1];
        ll d=0;
        rep1(i,1,n){
            rep1(j,1,m){
                cin>>a[i][j];
            }
        }
        rep1(i,1,n) {
            rep1(j,1,m){
                char t; cin>>t;
                if(t=='0') d+=a[i][j];
                else d-=a[i][j];
                tp[i][j]=t-'0';
                tp[i][j]+=tp[i-1][j]+tp[i][j-1]-tp[i-1][j-1];
            }
        }
        d=abs(d);
        ll gcd=0;
        rep1(i,k,n){
            rep1(j,k,m){
                ll c=tp[i][j]-tp[i-k][j]-tp[i][j-k]+tp[i-k][j-k];
                c=c-(k*k-c);
                c=abs(c);
                gcd=__gcd(gcd,c);
            }
        }
        if(gcd>0 && d%gcd==0 || d==0) eprint("YES")
        else eprint("NO")
    }

    return 0;
}