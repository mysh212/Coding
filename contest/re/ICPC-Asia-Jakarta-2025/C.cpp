// Author : ysh
// 2026/10/29 Thu 18:27:32
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;cin>>n>>m;
    vc<int>f(n);
    cin>>f;

    vc<vc<int>>mark(n, vector<int>(2, -1));
    re(i, n - 1) {
        #define n m
        if((!(m & 1)) && (f[i] + f[i + 1]) <= ((n >> 1) + 1)) {
            mark[i + 1][0] = 0;
            // mark[i + 1][2] = 
        }
        if((m & 1) && (f[i] + f[i + 1]) <= (n >> 1)) {
            mark[i + 1][0] = 0;
        }
        if((m & 1) && (f[i] + f[i + 1]) <= ((n + 1) >> 1)) {
            mark[i + 1][1] = 1;
        }
        if((!(m & 1)) && (f[i] + f[i + 1]) <= (n >> 1)) {
            mark[i + 1][1] = 1;
        }

        // if(f[i] + f[i + 1] <= m) {
        //     mark[i + 1][0] = 0;
        //     mark[i + 1][1] = 1;
        // }
        if(f[i + 1] <= ((n + 1) >> 1)) {
            mark[i + 1][1] = 0;
        }
        if(f[i + 1] <= (n >> 1)) {
            mark[i + 1][0] = 1;
        }
    }

    repo(&i, mark) {
        debug(i);
    }
}