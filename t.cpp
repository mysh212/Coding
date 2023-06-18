// Author : ysh
// Sun 06/18/2023 15:11:48.38
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    deque<int>f(a);
    int last = 0;
    for(int &i : f) {
        cin>>i;
        i = last += i;
    }
    f.push_front(0);
    a++;

    vector<vector<int>>v(2,vector<int>(a));
    for(int i = 1;i<=b;i++) {
        auto found = f.begin();
        for(int j = 0;j<a;j++) {
            while(f.at(j) - *found > c) found = next(found);
            v.at(i & 1).at(j) = v.at(!(i & 1)).at(found - f.begin()) + (f.at(j) - *found);
        }
        for(int j = 1;j<a;j++) {
            v.at(i & 1).at(j) = max(v.at(i & 1).at(j),v.at(i & 1).at(j - 1));
        }
    }
    cout<<v.at(b & 1).at(a - 1);
    return 0;
}