// Author : ysh
// 07/08/2022 Fri  8:38:58
// https://judge.tcirc.tw/ShowProblem?problemid=d001
#include<bits/stdc++.h>
using namespace std;
int f();
int g();
int ip();
int f() {
    return (ip() << 1) - 1;
}
int g() {
    return ip() + (ip() << 1) - 3;
}
int ip() {
    string a;
    cin>>a;
    if(a == "f") {
        return f();
    }
    if(a == "g") {
        return g();
    }
    return stoi(a);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout<<ip();
    return 0;
}
