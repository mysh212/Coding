// Author : ysh
// 2024/12/14 Sat 21:59:42
#include<bits/stdc++.h>
using namespace std;
#include<fast>
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vc<int>f(n);

    cin>>f;
    sort(all(f));
    
    cout<<f;
    return 0;
}