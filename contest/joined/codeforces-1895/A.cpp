// Author : ysh
// 2023/11/03 Fri 22:51:42
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b,c;cin>>a>>b>>c;
        if(abs(0 - a) < abs(0 - b)) cout<<b + max(0,((b - a) - c))<<"\n";
        else cout<<a<<"\n";
    }
    return 0;
}