// Author : ysh
// 04/23/2022 Sat 18:12:44.78
#include<bits/stdc++.h>
using namespace std;
vector<int>f(200001),v(200001,INT_MAX);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>c;
    c.push({0,0});
    f[200000] = v[200000] = INT_MAX;
    for(int i = 0;i<a;i++) {
        cin>>f[i];
        int mmin = 200000;
        while(!c.empty()) {
            auto now = c.top();
            if(now.second >= i - (b << 1) - 1) {
                mmin = now.second;
                break;
            }
            c.pop();
        }
        if(i - b >= 0) v[i] = v[mmin] + f[i];
        else v[i] = f[i];
        // for(int i : v) cout<<i<<" ";
        // cout<<'\n';
        c.push({v[i],i});
            // for(int i : v) cout<<i<<" ";
            // cout<<"\n";
    }
    cout<<*min_element(f.begin() + a - b,f.begin() + a + 1);
    return 0;
}