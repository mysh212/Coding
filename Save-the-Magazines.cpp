// Author : ysh
// 11/20/2022 Sun  7:23:30.60
// https://codeforces.com/contest/1743/problem/C
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a;cin>>a;
        vector<bool>f(a);
        vector<int>g(a);
        for(int i = 0;i<a;i++) {
            char tmp;cin>>tmp;
            if(tmp == '1') f.at(i) = 1;
        }
        for(int &i : g) {
            cin>>i;
        }
        vector<int>l(a),r(a);
        for(int i = 0;i<a;i++) {
            if(f.at(i)) {
                if(i == 0) {
                    r.at(0) = g.at(0);
                    continue;
                }
                r.at(i) = max({l.at(i - 1) + g.at(i - 1),l.at(i - 1) + g.at(i),r.at(i - 1) + g.at(i)});
                l.at(i) = max(r.at(i - 1),l.at(i - 1) + g.at(i - 1));
                if(l.at(i) > r.at(i)) r.at(i) = l.at(i);
                continue;
            }
            if(i == 0) continue;
            l.at(i) = r.at(i - 1);
            r.at(i) = r.at(i - 1);
        }
        cout<<r.at(a - 1)<<"\n";
    }
    return 0;
}