// Author : ysh
// 2023/06/29 Thu 11:47:53
#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
vector<int>f({1,1});
int check(int x) {
    if(f.size() < x) f.push_back(check(x - 1) + check(x - 2));
    return f.at(x - 1);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    while(cin>>a>>b) {
        cout<<check(__gcd(a,b))<<"\n";
    }
    return 0;
}