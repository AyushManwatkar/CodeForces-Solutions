#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,avx,avx2,fma,tune=native")

#include <bits/stdc++.h>
using namespace std;

#define PI (3.141592653589)
#define MOD 1000000007
#define PB push_back
#define IS insert
#define MP make_pair
#define FF first
#define SS second
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MAX3(a, b, c) max(c, max(a, b))
#define MAX4(a, b, c, d) max(d, max(c, max(a, b)))
#define MIN3(a, b, c) min(c, min(a, b))
#define MIN4(a, b, c, d) min(d, min(c, min(a, b)))
#define RFR(n) for(int i = (n) - 1; i >= 0; --i)
#define REP1(i, a, b) for(long long i = (a); i <= (b); ++i)
#define FR(n) for(long long i = 0; i < (n); ++i)
#define NESFR(x, y) for(long long i = 0; i < (x); ++i) for(long long j = 0; j < (y); ++j)
#define REP(i, a, b) for(long long i = (a); i < (b); ++i)
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define PLL pair<ll, ll>
#define PRINT(x) cout << (x)
#define SPRINT(x) cout << (x) << " "
#define EPRINT(x) cout << (x) << endl
#define DSPRINT(ds) for(const auto& x : (ds)) cout << x << " "; cout << endl

typedef long long ll;
typedef long double ld;
typedef vector<ll> VI;
typedef vector<ld> VD;
typedef vector<string> VS;
typedef vector<PLL> VPLL;

//a[2] < a[3]
void handleLessThan(ll a[4]) {
    EPRINT(a[0] + a[2]);
}

//a[2] == a[3]
void handleEqual(ll a[4]) {
    a[0] += a[2];
    while (a[0] % a[1] == 0) {
        a[0] /= a[1];
    }
    EPRINT(a[0]);
}

//general case
void handleGeneralCase(ll a[4]) {
    while (true) {
        ll p = a[3];
        if (a[0] == 1) break;

        if (a[2] >= p) {
            a[2] -= p;
            a[0] += p;
            while (a[0] % a[1] == 0) a[0] /= a[1];
            a[3] = a[1] - a[0] % a[1];
        } else {
            a[0] += a[2];
            a[2] = 0;
            break;
        }
    }
    if (a[2] != 0) {
        EPRINT(a[2] % (a[1] - 1) + 1);
    } else {
        EPRINT(a[0]);
    }
}

int main() {
    FAST_IO;
    ll t;
    cin >> t;

    while (t--) {
        ll a[4];
        for (int i = 0; i < 3; ++i) cin >> a[i];
        a[3] = a[0] % a[1];
        a[3] = a[1] - a[3];

        if (a[2] < a[3]) {
            handleLessThan(a);
        } else if (a[2] == a[3]) {
            handleEqual(a);
        } else {
            handleGeneralCase(a);
        }
    }

    return 0;
}
