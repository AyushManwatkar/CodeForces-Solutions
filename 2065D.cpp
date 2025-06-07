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
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define sz(x) ((ll)(x).size())
#define max3(a,b,c) max(c,max(a,b))
#define max4(a,b,c,d) max(d,max(c,max(a,b)))
#define min3(a,b,c) min(c,min(a,b))
#define min4(a,b,c,d) min(d,min(c,min(a,b))
#define rfr(n) for(ll i=(n)-1;i>=0;i--)
#define rep1(i,a,b) for(ll i=(a);i<=(b);i++)
#define fr(n) for(ll i=0;i<(n);i++)
#define nesfr(x,y) for(ll i=0;i<(x);i++)for(ll j=0;j<(y);j++)
#define rep(i,a,b) for(ll i=(a);i<(b);i++)
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define pll pair<ll,ll>
#define umap unordered_map
#define uset unordered_set
#define pq_max priority_queue<ll>
#define pq_min priority_queue<ll,vector<ll>,greater<ll>>
#define print(x) cout<<x;
#define sprint(x) cout<<x<<" ";
#define eprint(x) cout<<x<<endl;
#define dsprint(ds) for(const auto& x:ds)cout<<x<<" ";cout<<endl;
#define sorta(ds) sort(all(ds))
#define sortd(ds) sort(rall(ds))
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<string> vs;
typedef vector<pll> vpll;
typedef set<ll> sll;
typedef unordered_map<ll,ll> umll;
typedef unordered_set<ll> usll;

ll calculate_score(const vll&arr){
    ll score=0;
    ll current_sum=0;
    fr(arr.size()){
        current_sum+=arr[i];
        score+=current_sum;
    }
    return score;
}

ll calculate_additional_score(const vector<vll>&arrays,ll prev,ll last,ll mask,ll m,const vll&sums){
    ll score_last=calculate_score(arrays[last]);
    ll sum_last=sums[last];
    ll used_length=__builtin_popcount(mask^(1<<last))*m;
    return score_last+sum_last*used_length;
}

int main(){
    fast;
    ll t;
    cin>>t;

    while(t--){
        ll n,m;
        cin>>n>>m;

        vector<vector<ll>> arrays(n,vector<ll>(m));
        vll sums(n);

        fr(n){
            ll current_sum=0;
            rep(j,0,m){
                cin>>arrays[i][j];
                current_sum+=arrays[i][j];
            }
            sums[i]=current_sum;
        }

        vector<vector<ll>> dp((1<<n),vector<ll>(n,-1));

        fr(n){
            dp[1<<i][i]=calculate_score(arrays[i]);
        }

        for(ll mask=1;mask<(1<<n);++mask){
            fr(n){
                if((mask>>i)&1){
                    rep(j,0,n){
                        if(i!=j&&((mask>>j)&1)){
                            if(dp[mask^(1<<i)][j]!=-1){
                                dp[mask][i]=max(dp[mask][i],dp[mask^(1<<i)][j]+calculate_additional_score(arrays,j,i,mask,m,sums));
                            }
                        }
                    }
                }
            }
        }

        ll max_score=-1;
        fr(n){
            max_score=max(max_score,dp[(1<<n)-1][i]);
        }

        cout<<max_score<<endl;
    }

    return 0;
}
