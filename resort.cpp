// Author : ysh
// 02/03/2022 Thu 18:41:00.24
// http://choj.me/problem/00075
#include<bits/stdc++.h>
using namespace std;
struct qs{
    queue<int>f;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int a[n] = {};
    int k = 0;
    qs q[n];
    for(int &i : a) {
        cin>>i;
        bool t = 0;
        for(int j = 0;j<k;j++) {
            if(i > q[j].f.front()) {
                q[j].f.push(i);
                t = 1;
                break;
            }
        }
        if(t) continue;
        q[k].f.push(i);
        k++;
    }
    //cout<<k;
    while(1) {
        bool t = 1;
        for(int i = 0;i<k;i++) {
            if(q[i].f.empty() == 1) continue;
            t = 0;
            cout<<q[i].f.front()<<" ";
            q[i].f.pop();
        }
        if(t) break;
    }
    return 0;
}