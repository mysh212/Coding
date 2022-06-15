// Author : ysh
// 06/11/2022 Sat 17:51:37.35
#include<bits/stdc++.h>
using namespace std;
int ip();
int f();
int g();
int h();
int ip() {
    string a;cin>>a;
    if(a == "f") {
        return f();
    }
    if(a == "g") {
        return g();
    }
    if(a == "h") {
        return h();
    }
    return stoi(a);
}
inline int f() {
    return (ip() << 1) - 3;
}
inline int g() {
    return (ip() << 1) + (ip()) - 7;
}
inline int h() {
    return (ip() * 3) - (ip() << 1) + ip();
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout<<ip();
    return 0;
}