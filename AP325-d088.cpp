// Author : ysh
// 03/05/2023 Sun  9:15:43.05
// https://judge.tcirc.tw/ShowProblem?problemid=d088
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n),g(n);
    vector<int>mark(n);
    for(int &i : f) {
        cin>>i;
    }
    for(int &j : g) {
        cin>>j;
    }

    vector<pair<int,int>>q;
    for(int i = 0;i<n;i++) {
        while(!q.empty() && q.back().first <= f.at(i)) q.pop_back();
        if(q.empty()) {
            if(i == 0) {
                mark.at(i) = g.at(i);
                q.push_back(make_pair(f.at(i),i));
                continue;
            }
            q.push_back(make_pair(f.at(i),i));
            mark.at(i) = max(mark.at(i - 1),g.at(i));
            continue;
        }
        auto now = q.back();
        if(now.second == 0) mark.at(i) = max(mark.at(i - 1),g.at(i));
        else mark.at(i) = max(mark.at(now.second - 1) + g.at(i),mark.at(i - 1));
        if(f.at(i - 1) < f.at(i)) q.push_back(make_pair(f.at(i),i));
    }
    for(int i : mark) cerr<<i<<" ";
    cerr<<"\n";
    cout<<mark.at(n - 1);
    return 0;
}