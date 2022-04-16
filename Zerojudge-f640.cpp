// Author : ysh
// 04/05/2022 Tue  7:45:16.00
#include<bits/stdc++.h>
using namespace std;
inline int f(int a) {
    return (a << 1) - 3;
}
inline int g(int a,int b) {
    return (a << 1) + b - 7;
}
inline int h(int a,int b,int c) {
    return (a * 3) - (b << 1) + c;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int>a,b;
    string c;
    while(cin>>c) {
        if(c == "f") {
            a.push_back(-1001);
            continue;
        }
        if(c == "g") {
            a.push_back(-1002);
            continue;
        }
        if(c == "h") {
            a.push_back(-1003);
            continue;
        }
        a.push_back(stoi(c));
    }
    while(!a.empty()) {
        int now = a.back();a.pop_back();
        if(now == -1001) {
            int aa = b.back();b.pop_back();
            b.push_back(f(aa));
            continue;
        }
        if(now == -1002) {
            int aa = b.back();b.pop_back();
            int bb = b.back();b.pop_back();
            b.push_back(g(aa,bb));
            continue;
        }
        if(now == -1003) {
            int aa = b.back();b.pop_back();
            int bb = b.back();b.pop_back();
            int cc = b.back();b.pop_back();
            b.push_back(h(aa,bb,cc));
            continue;
        }
        b.push_back(now);
    }
    cout<<b.front();
    return 0;
}