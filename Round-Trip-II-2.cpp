// Author : ysh
// 2023/11/30 Thu 00:06:34
// https://cses.fi/problemset/task/1678
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a);
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
    }

    vector<bool>mark(a),mk(a);
    vector<int>now;
    function<void(int)> check = [&] (int x) {
        if(mk.at(x)) {
            vector<int>tmp;
            while(!now.empty() && now.back() != x) tmp.push_back(now.back()),now.pop_back();
            cout<<tmp.size() + 2<<"\n"<<x + 1<<" ";
            reverse(tmp.begin(),tmp.end());
            for(int &i : tmp) cout<<i + 1<<" ";
            cout<<x + 1;
            exit(0);
        }
        if(mark.at(x)) return;
        mark.at(x) = 1;
        mk.at(x) = 1;
        now.push_back(x);
        for(int &i : f.at(x)) {
            check(i);
        }
        mk.at(x) = 0;
        now.pop_back();
    };

    for(int i = 0;i<a;i++) {
        if(!mark.at(i)) check(i);
    }
    cout<<"IMPOSSIBLE";
    return 0;
}