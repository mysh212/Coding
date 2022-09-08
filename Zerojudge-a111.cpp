// Author : ysh
// 09/04/2022 Sun 13:41:52.67
#include<bits/stdc++.h>
using namespace std;
vector<int>f({0});
int check(int n) {
    if(f.size() >= n + 1) return f[n];
    f.push_back((n * n) + check(n - 1));
    return f[n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        if(n == 0) break;
        cout<<check(n)<<"\n";
    }
    return 0;
}