// Author : ysh
// 07/29/2022 Fri 16:07:36.84
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i = 1;i<=b;i++) {
        q.push(0);
    }
    for(int i = 0;i<a;i++) {
        int tmp;cin>>tmp;
        int now = q.top();q.pop();
        q.push(now + tmp);
    }
    int mmax = 0;
    while(!q.empty()) {
        mmax = q.top();q.pop();
    }
    cout<<mmax;
    return 0;
}