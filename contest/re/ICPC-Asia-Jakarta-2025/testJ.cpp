#include <bits/stdc++.h>
#define int int64_t
using namespace std;
signed main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(0);
    for(int i = 1; i <= 64; i++) {
        cout << i << " & " << (i<<1) <<  " = " << (i & (i<<1)) << '\n';
        
    }
    for(int i = 1; i <= 64; i++) {
        cout << i << " | " << (i<<1) <<  " = " << (i | (i<<1)) << '\n';
    }
}