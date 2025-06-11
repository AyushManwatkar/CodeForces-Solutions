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

typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<ld> vld;
typedef vector<string> vs;
typedef vector<pll> vpll;
typedef map<ll, ll> mll;
typedef set<ll> sll;
typedef unordered_map<ll, ll> umll;
typedef unordered_set<ll> usll;
typedef priority_queue<ll> pq_max;
typedef priority_queue<ll, vector<ll>, greater<ll>> pq_min;
#define umap unordered_map
#define uset unordered_set

#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define pi (3.14159265358979323846)
#define mod 1000000007
#define inf LLONG_MAX
#define pb push_back
#define ppb pop_back
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
#define print(x) cout << x;
#define sprint(x) cout << x << " ";
#define eprint(x) cout << x << endl;
#define sorta(ds) sort(all(ds))
#define sortd(ds) sort(rall(ds))

#define rfr(n) for(ll i=(n)-1; i>=0; i--)
#define rep1(i,a,b) for(ll i=(a); i<=(b); i++)
#define fr(n) for(ll i=0; i<(n); i++)
#define nesfr(x,y) for(ll i=0; i<(x); i++) for(ll j=0; j<(y); j++)
#define rep(i,a,b) for(ll i=(a); i<(b); i++)

#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v) {for (auto &it : v)cin >> it; return istream;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
template <typename T> // cout << set<T>
ostream& operator<<(ostream& os, const set<T>& v) {for (auto it : v) {os << it; if (it != *v.rbegin())os << " ";} os << "\n"; return os;}
template <typename T, typename S> // cout << map<T,S>
ostream& operator<<(ostream& os, const map<T, S>& v) {for (auto it : v) os << it.first << " " << it.second << "\n"; return os;}

bool isPrime(ll n) {if (n <= 1)return false; if (n <= 3)return true; if (n % 2 == 0 || n % 3 == 0)return false; for (int i = 5; i * i <= n; i = i + 6)if (n % i == 0 || n % (i + 2) == 0)return false; return true;}
bool isPowerOfTwo(ll x) {if (x == 0)return false; return (x & (x - 1)) == 0;}
bool isPerfectSquare(ll x) {if (x >= 0) {ll sr = sqrt(x); return (sr * sr == x);} return false;}

int main() {
    fast;
    ll t; cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        usll strt,end;
        fr(n){
            pll seg; cin>>seg.ff>>seg.ss;
            strt.insert(seg.ff);
            end.insert(seg.ss);
        }
        bool lk=(strt.find(k) != strt.end());
        bool rk=(end.find(k) != end.end());
        if(lk && rk) yes
        else no
    }

    return 0;
}