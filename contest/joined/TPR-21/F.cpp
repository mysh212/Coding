// Author : ysh
// 05/31/2022 Tue  9:35:03.21
#include<bits/stdc++.h>
using namespace std;
const int MAX = ((int) 1e7) + 5;
int sig = 0;
inline bool t(int);
#define p system("pause");
vector<int>f;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    f.resize(c);
    for(int i = 0;i<c;i++) {
        cin>>f[i];
        sig += f[i];
        if(i != 0) f[i] = f[i] + f[i - 1];
        if(sig > a) break;
    }
    vector<int>v(MAX);
    int r = 0;
    // for(int i = 0;i<a;i++) {
    //     if((sig * r) + f[i] < a) {
    //         v[(sig * r) + f[i]] = 1;
    //     }
    // }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,a});
    vector<bool>mark(a + 1);
    for(int i = 0;i<c;i++) {
        for(int j = f[i];j <= a;j = j + sig) {
            mark[j] = 1;
        }
    }
    // for(bool i : mark) cout<<(int) i<<" ";
    // cout<<"\n";
    // return 0;
    for(int i = a - 1;i >= 0;i--) {
        if(!mark[i]) {
            v[i] = INT_MAX;
            q.push({v[i],i});
            continue;
        }
        auto now = q.top();
        while(!q.empty()) {
            if(now.second > i + b) {
                q.pop();now = q.top();
                continue;
            }
            break;
        }
        // p
        if(now.first == INT_MAX) {
            cout<<-1;
            return 0;
        }
        v[i] = now.first + 1;
        q.push({v[i],i});
    }
    // for(int i = 0;i<=a;i++) {
    //     if(v[i] == INT_MAX) cout<<"M ";
    //     else cout<<v[i]<<" ";
    // }
    // cout<<"\n";
    // for(int i = 0;i<a;i++) {
    //     cout<<mark[i]<<" ";
    // }
    // cout<<"\n";
    cout<<*min_element(v.begin() + 1,v.begin() + 1 + b);
    return 0;
}
inline bool t(int x) {
    return binary_search(f.begin(),f.end(),(x % sig));
}