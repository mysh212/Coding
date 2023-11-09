// Author : ysh
// 2023/11/08 Wed 19:32:37
// https://codeforces.com/problemset/problem/1895/D
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vc<int>f(n - 1);
    cin>>f;

    re(i,1,n - 1) f.at(i) = f.at(i) ^ f.at(i - 1);

    vc<int>mark(30);
    re(i,1,n) {
        int t = 0;
        int tmp = i;
        while(tmp != 0) {
            mark.at(t++) += tmp & 1;
            tmp = tmp >> 1;
        }
    }

    vc<int>mk(30);
    repo(i,f) {
        int t = 0;
        while(i != 0) {
            mk.at(t++) += i & 1;
            i = i >> 1;
        }
    }

    int ans = 0;
    re(i,30) if(mark.at(i) != mk.at(i)) ans = ans | (1 << i);

    repo(&i,f) i = i ^ ans;
    outs(ans);
    outl(f);
    return 0;
}