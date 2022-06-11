// Author : ysh
// 05/31/2022 Tue 21:55:19.94
// https://cses.fi/problemset/task/1645/
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    for(int &i : f) {
        cin>>i;
        // i = i * (-1);
    }
    priority_queue<pair<int,int>>q;
    q.push({0,f[0]});
    cout<<"0 ";
    for(int i = 1;i<n;i++) {
        // if(i == 3) {
        //     while(!q.empty()) {
        //         cout<<q.top().first<<" "<<q.top().second<<" ";q.pop();
        //     }
        //     return 0;
        // }
        auto now = q.top();
        bool c = 0;
        while(!q.empty()) {
            if(now.second >= f[i]) {
                q.pop();
                if(q.empty()) {
                    q.push({i,f[i]});
                    cout<<"0 ";
                    c = 1;
                    break;
                }
                now = q.top();
                continue;
            }
            break;
        }
        if(c) continue;
        cout<<now.first + 1<<" ";
        q.push({i,f[i]});
    }
    return 0;
}