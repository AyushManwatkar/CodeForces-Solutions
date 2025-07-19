#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr);

int dp[20][2][2]; // pos, tightL, tightR
string L, R;
ll l_val, r_val;

// Helper function to count consecutive matching digits from right
ll countSameDigits(ll a, ll b) {
    string xa = to_string(a), xb = to_string(b);
    ll cnt = 0;
    ll minl = min(xa.size(), xb.size());
    
    for(ll i = 0; i < minl; i++) {
        if(xa[xa.size()-1-i] == xb[xb.size()-1-i]) {
            cnt++;
        } else {
            break;
        }
    }
    return cnt;
}

int solve(int pos, bool tightL, bool tightR, string &current) {
    // Base case: if we've processed all digits
    if (pos == L.size()) {
        ll x = 0;
        // Convert current string to number
        for(char c : current) {
            x = x * 10 + (c - '0');
        }
        
        // Calculate f(l,x) + f(x,r)
        return countSameDigits(l_val, x) + countSameDigits(x, r_val);
    }
    
    // Memoization check
    int &res = dp[pos][tightL][tightR];
    if (res != -1) return res;
    
    // Determine digit bounds based on tight constraints
    int lo = tightL ? (L[pos] - '0') : 0;
    int hi = tightR ? (R[pos] - '0') : 9;
    
    res = INT_MAX;
    
    // Try all valid digits at current position
    for (int d = lo; d <= hi; ++d) {
        current[pos] = '0' + d;
        
        // Update tight constraints for next position
        bool nextTightL = tightL && (d == lo);
        bool nextTightR = tightR && (d == hi);
        
        // Recurse to next position
        res = min(res, solve(pos + 1, nextTightL, nextTightR, current));
    }
    
    return res;
}

int main() {
    fast;
    ll t; 
    cin >> t;
    
    while(t--) {
        cin >> l_val >> r_val;
        
        // Step 1: Convert to strings and pad L to match R's length
        L = to_string(l_val);
        R = to_string(r_val);
        
        while (L.size() < R.size()) {
            L = '0' + L;
        }
        
        // Step 2-5: Initialize DP and solve
        memset(dp, -1, sizeof(dp));
        string current(R.size(), '0');
        
        cout << solve(0, true, true, current) << "\n";
    }
    
    return 0;
}
