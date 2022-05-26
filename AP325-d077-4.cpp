// Author : ysh
// 04/29/2022 Fri 14:15:23.87
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
    }
    deque<pair<int,int>>q;
    vector<int>aa(a);
    q.push_back(make_pair(0,-b - 1));
    for(int i = 0;i<a;i++) {
        while(q.front().second < i - b - b - 1) {
            q.pop_front();
        }
        aa[i] = q.front().first + f[i];
        while(q.back().first >= aa[i]) {
            q.pop_back();
        }
        q.push_back({aa[i],i});
    }
    // for(int i : aa) cout<<i<<" ";
    // cout<<"\n";
    cout<<*min_element(aa.end() - b - 1,aa.end());
    return 0;
}