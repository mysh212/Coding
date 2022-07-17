// Author : ysh
// 07/17/2022 Sun 11:39:24
// https://judge.tcirc.tw/ShowProblem?problemid=d033
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    queue<int>q;
    int now = 0;
    int mmax = 0;
    for(int i = 0;i<b;i++) {
        int tmp;cin>>tmp;
        f.at(tmp)++;
        q.push(tmp);
        if(f.at(tmp) == 1) {
            now++;
            mmax = now;
        }
    }
    for(int i = b;i<a;i++) {
        int tmp;cin>>tmp;
        f.at(tmp)++;
        if(f.at(tmp) == 1) {
            now++;
        }
        int n = q.front();q.pop();
        f.at(n)--;
        if(f.at(n) == 0) now--;
        q.push(tmp);
        mmax = max(mmax,now);
    }
    cout<<mmax;
    return 0;
}
