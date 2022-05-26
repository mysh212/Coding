// Author : ysh
// 04/02/2022 Sat 14:21:24.77
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    int c[a] = {},d[a] = {};
    for(int i = 0;i<a;i++) {
        cin>>c[i];
    }
    for(int i = 0;i<a;i++) {
        cin>>d[i];
    }
    int sum = 0;
    queue<int>q;
    for(int i = 0;i<a;i++) {
        if(d[i] >= b) sum += d[i];
        if(sum >= c[i]) {
            q.push(i + 1);
            sum = 0;
        }
    }
    cout<<q.size()<<"\n";
    while(!q.empty()) {
        cout<<q.front()<<" ";q.pop();
    }
    return 0;
}