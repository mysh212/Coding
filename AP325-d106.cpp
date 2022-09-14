// Author : ysh
// 09/10/2022 Sat 15:06:49.28
// https://judge.tcirc.tw/ShowProblem?problemid=d106
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    unordered_map<int,int>m;
    int t = 0;
    for(int &i : f) {
        cin>>i;
        if(m.find(i) == m.end()) m.insert({i,t++});
        i = m.find(i)->second;
    }
    vector<vector<int>>l(n);
    for(int i = 0;i<(n - 1);i++) {
        int a,b;cin>>a>>b;
        l.at(a).push_back(b);
    }
    vector<int>color(t);
    vector<bool>mark(n);
    int mmax = 0;
    function<void(int)> check = [&] (int x) {
        if(mark.at(x)) return;
        mark.at(x) = 1;
        color.at(f.at(x))++;
        bool c = 0;
        for(int &i : l.at(x)) {
            c = 1;
            check(i);
        }
        if(!c) {
            mmax = max(mmax,*max_element(color.begin(),color.end()));
        }
        color.at(f.at(x))--;
    };
    check(0);
    cout<<mmax;
    return 0;
}