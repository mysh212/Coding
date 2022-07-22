// Author : ysh
// 07/21/2022 Thu 21:33:17.07
// https://judge.tcirc.tw/ShowProblem?problemid=d048
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    priority_queue<long long,vector<long long>,greater<long long>>q;
    for(int i = 0;i<n;i++) {
        int tmp;cin>>tmp;
        q.push(tmp);
    }
    long long ans = 0;
    while(q.size() > 1) {
        auto f = q.top();q.pop();
        auto s = q.top();q.pop();
        ans = ans + (f + s);
        q.push((f + s));
    }
    cout<<q.top()<<"\n"<<ans;
    return 0;
}