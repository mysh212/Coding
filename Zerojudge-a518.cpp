// Author : ysh
// 06/20/2022 Mon 11:54:46.64
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    while(cin>>a>>b) {
        if(a > b) swap(a,b);
        if(a == -1 && b == -1) {
            break;
        }
        cout<<min(b - a,(a + 100) - b)<<"\n";
    }
    return 0;
}