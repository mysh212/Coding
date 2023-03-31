// Author : ysh
// 03/31/2023 Fri  8:30:06.82
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c;cin>>a>>b>>c;
    vector<int>v(a);
    for(int &i : v) {
        cin>>i;
    }

    vector<vector<int>>f(a);
    for(int i = 1;i<a;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        f.at(b).push_back(a);
    }

    vector<int>mark(a);
    int t = 0;
    vector<pair<int,int>>tt(a);
    function<int(int,int)> check = [&] (int last,int x) {
        tt.at(x).first = t++;
        int sig = 0;
        for(int &i : f.at(x)) {
            if(i != last) sig = sig + check(x,i);
        }
        tt.at(x).second = t++;
        return mark.at(x) = sig + v.at(x);
    };
    check(-1,c - 1);

    while(b--) {
        int a,b;cin>>a>>b;
        a--;b--;
        if(tt.at(b).first < tt.at(a).first || tt.at(a).second < tt.at(b).second) cout<<"-1\n";
        else cout<<mark.at(b)<<"\n";
    }
    return 0;
}