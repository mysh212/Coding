// Author : ysh
// 10/27/2022 Thu 19:33:18.65
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
    vector<pair<int,int>>q;
    q.push_back({0,f[0]});
    cout<<"0 ";
    for(int i = 1;i<n;i++) {
        // if(i == 3) {
        //     while(!q.empty()) {
        //         cout<<q.top().first<<" "<<q.top().second<<" ";q.pop();
        //     }
        //     return 0;
        // }
        auto now = q.back();
        bool c = 0;
        while(!q.empty()) {
            if(now.second >= f[i]) {
                q.pop_back();
                if(q.empty()) {
                    q.push_back({i,f[i]});
                    cout<<"0 ";
                    c = 1;
                    break;
                }
                now = q.back();
                continue;
            }
            break;
        }
        if(c) continue;
        cout<<now.first + 1<<" ";
        q.push_back({i,f[i]});
    }
    return 0;
}