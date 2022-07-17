// Author : ysh
// 07/17/2022 Sun 12:49:37
// https://judge.tcirc.tw/ShowProblem?problemid=d034
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    map<int,int>f;
    queue<int>q;
    int now = 0;
    int mmax = 0;
    for(int i = 0;i<b;i++) {
        int tmp;cin>>tmp;
        f[tmp]++;
        q.push(tmp);
        if(f[tmp] == 1) {
            now++;
            mmax = now;
        }
    }
    for(int i = b;i<a;i++) {
        int tmp;cin>>tmp;
        f[tmp]++;
        if(f[tmp] == 1) {
            now++;
        }
        int n = q.front();q.pop();
        f[n]--;
        if(f[n] == 0) {
            f.erase(n);
            now--;
        }
        q.push(tmp);
        mmax = max(mmax,now);
    }
    cout<<mmax;
    return 0;
}