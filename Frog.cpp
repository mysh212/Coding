// Author : ysh
// 2024/08/15 Thu 00:15:21
// https://codeforces.com/group/j50SrY6hsZ/contest/542817/problem/A
#include<bits/stdc++.h>
using namespace std;
const int R = int(1e9) + 7;
#define int long long
array<int,3> operator*(array<int,3>a,array<int,3> b) {
    return {a[0] * b[0] + (a[1] * b[1] % R) * (a[2] - 1),a[1] * b[0] + a[0] * b[1] + (a[1] * b[1] % R) * (a[2] - 2),a[2]};
}
array<int,3> operator%(array<int,3>a,int b) {
    return {a[0] % b,a[1] % b,a[2]};
}
auto check(auto a,int b) {
    if(b == 1) return a;
    auto tmp = check(a,b >> 1);
    tmp = tmp * tmp % R;

    if(b & 1) return tmp * a % R;
    return tmp;
}
inline int rev(int x) {
    return check(x,R - 1 - 1);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int tmp = rev(a - 1);
    array<int,3> left({0,tmp,a}),right({1,0,a});

    cout<<(check(left,b) * right)[0];
    return 0;
}