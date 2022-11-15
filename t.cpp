// Author : ysh
// 11/15/2022 Tue  6:38:45.93
#include<bits/stdc++.h>
using namespace std;
inline bool yes(int x) {
    if(x % 400 == 0) return 1;
    if(x % 100 == 0) return 0;
    if(x % 4 == 0) return 1;
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    while(a--) {
        b = b + 1;
        while(!yes(b)) {
            b = b + 1;
        }
    }
    cout<<b;
    return 0;
}