#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool isSquare(long long area) {
    long long side = sqrt(area);
    return side * side == area;
}

bool canArrange(int w1, int h1, int w2, int h2, int w3, int h3) {
    // Check if total area forms a perfect square
    long long totalArea = (long long)w1 * h1 + (long long)w2 * h2 + (long long)w3 * h3;
    if (!isSquare(totalArea)) return false;
    
    int side = sqrt(totalArea);
    
    // Try all possible arrangements
    vector<pair<int, int>> rects = {{w1, h1}, {w2, h2}, {w3, h3}};
    
    // Try all permutations
    sort(rects.begin(), rects.end());
    do {
        int a = rects[0].first, b = rects[0].second;
        int c = rects[1].first, d = rects[1].second;
        int e = rects[2].first, f = rects[2].second;
        
        // Arrangement 1: Three rectangles in a row
        if (b == d && d == f && b == side && a + c + e == side) return true;
        
        // Arrangement 2: Three rectangles in a column
        if (a == c && c == e && a == side && b + d + f == side) return true;
        
        // Arrangement 3: Two rectangles side by side, third on top
        if (a == c && b == d && a + c == side && b + f == side && e == side) return true;
        
        // Arrangement 4: Two rectangles stacked, third on right
        if (b == d && a == c && b + d == side && a + e == side && f == side) return true;
        
        // Arrangement 5: L-shape - first rect spans width, others stack vertically
        if (a == side && c == e && d == f && c + e == side && b == d + f) return true;
        
        // Arrangement 6: L-shape - first rect spans height, others side by side
        if (b == side && d == f && c == e && d + f == side && a == c + e) return true;
        
        // Additional L-shape arrangements
        if (a == side && b + d == side && c == e && f == side && d == f) return true;
        if (b == side && a + c == side && d == f && e == side && c == e) return true;
        
    } while (next_permutation(rects.begin(), rects.end()));
    
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        
        // Try all orientations for each rectangle
        bool possible = false;
        
        for (int mask = 0; mask < 8 && !possible; mask++) {
            int w1 = l1, h1 = b1;
            int w2 = l2, h2 = b2;
            int w3 = l3, h3 = b3;
            
            if (mask & 1) swap(w1, h1);
            if (mask & 2) swap(w2, h2);
            if (mask & 4) swap(w3, h3);
            
            if (canArrange(w1, h1, w2, h2, w3, h3)) {
                possible = true;
            }
        }
        
        cout << (possible ? "YES" : "NO") << "\n";
    }
    
    return 0;
}
