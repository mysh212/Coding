// Author : ysh
// 10/28/2022 Fri 15:35:18.30
// https://judge.tcirc.tw/ShowProblem?problemid=d099
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

vector<int>f;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    f.resize(a);
    vector<vector<int>>v(a);
    for(int &i : f) {
        cin>>i;
    }
    vector<int>in(a);
    while(b--) {
        int a,b;cin>>a>>b;
        a--;b--;
        in.at(b)++;
        v.at(a).push_back(b);
        // re.at(b).push_back(a);
    }
    vector<int>line;
    queue<int>q;
    for(int i = 0;i<a;i++) {
        if(in.at(i) == 0) q.push(i);
    }
    while(!q.empty()) {
        int now = q.front();q.pop();
        line.push_back(now);
        for(int &i : v.at(now)) {
            if(--in.at(i) == 0) q.push(i);
        }
    }
    vector<vector<int>>re(a);
    in = vector<int>(a);
    for(int &i : line) {
        for(int &j : v.at(i)) {
            if(in.at(j) == in.at(i) + f.at(i)) {
                in.at(j) = in.at(i) + f.at(i);
                re.at(j).push_back(i);
            }
            if(in.at(j) < in.at(i) + f.at(i)) {
                in.at(j) = in.at(i) + f.at(i);
                re.at(j) = vector<int>({i});
            }
        }
    }
    set<int>s;
    function<void(int)> check = [&] (int x) {
        s.insert(x);
        for(int &i : re.at(x)) check(i);
        return;
    };
    check(line.at(a - 1));
    cout<<in.at(line.back()) + f.at(line.back())<<"\n";
    for(int i : s) cout<<i + 1<<" ";
    return 0;
}