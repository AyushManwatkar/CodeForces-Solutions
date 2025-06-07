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

#define pi 3.141592653589
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define max3(a, b, c) max(a, max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define min3(a, b, c) min(a, min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define rfr(n) for(int i = (n) - 1; i >= 0; --i)
#define rep1(i, a, b) for(long long i = (a); i <= (b); ++i)
#define fr(n) for(long long i = 0; i < (n); ++i)
#define nesfr(x, y) for(long long i = 0; i < (x); ++i) for(long long j = 0; j < (y); ++j)
#define rep(i, a, b) for(long long i = (a); i < (b); ++i)
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pll pair<ll, ll>
#define print(x) cout << (x);
#define sprint(x) cout << (x) << " ";
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<ld> vd;
typedef vector<string> vs;
typedef vector<pll> vpll;

int main() {
    fast;
    ll t; cin >> t;
    while(t--){
        ll n,k; cin>>n>>k;
        vi arr(n);
        fr(n) cin>>arr[i];

        ll csum=0;
        vi temp=arr;
        temp[0]+=k;

        ll maxv=temp[0];
        ll maxi=0;
        rep(i,1,n){
            if(temp[i]>maxv) {
                maxv=temp[i];
                maxi=i;
            }
        }
        fr(n){
            if(i==maxi){
                sprint(0)
            }else{
                if(arr[i]+csum+k>=maxv){
                    sprint(i)
                }else{
                    sprint(i+1)
                }
            }
            csum+=arr[i];
        }
        cout<<endl;
    }
    return 0;
}
