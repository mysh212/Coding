// Author : ysh
// 11/04/2022 Fri 15:27:23.36
// https://cses.fi/problemset/task/1137
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a);
    vector<int>re(a),r(a);
    for(int &i : r) {
        cin>>i;
    }
    vector<int>v(r.begin(),r.end());
    for(int i = 1;i<a;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }
    function<int(int,int)> check = [&] (int last,int x) {
        re.at(x) = last;
        for(int &i : f.at(x)) {
            if(i != last) v.at(x) += check(x,i);
        }
        return v.at(x);
    };
    re.at(0) = -1;
    check(-1,0);
    while(b--) {
        int a,b;cin>>a>>b;
        b--;
        if(a == 1) {
            int c;cin>>c;
            int tmp = c;
            c = c - r.at(b);
            r.at(b) = tmp;
            while(b != -1) {
                v.at(b) += c;
                b = re.at(b);
            }
            continue;
        }
        cout<<v.at(b)<<"\n";
    }
    return 0;
}