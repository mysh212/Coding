// Author : ysh
// 03/02/2023 Thu 13:54:50.85
// https://tioj.ck.tp.edu.tw/problems/2189
// NF
#include<bits/stdc++.h>
using namespace std;
void ft(int &a,int &b,int c) {
    if(c > a) {
        swap(a,b);
        swap(a,c);
    } else if(c > b) {
        swap(b,c);
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<pair<int,int>>>f(n);
    // vector<int>to(n);
    for(int i = 1;i<n;i++) {
        int a,b,c;cin>>a>>b>>c;
        f.at(a).push_back({b,c});
        f.at(b).push_back({a,c});
    }

    function<pair<int,int>(int,int)> check = [&] (int last,int x) {
        int mmax = 0;
        int d = 0;
        int secd = 0;
        for(auto &i : f.at(x)) {
            if(i.first == last) continue;
            auto tmp = check(x,i.first);
            mmax = max(mmax,tmp.second);
            ft(d,secd,tmp.first + i.second);
        }
        return make_pair(d,max(d + secd,mmax));
    };

    cout<<check(-1,0).second;
    return 0;
}