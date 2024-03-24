// Author : ysh
// 2024/02/13 Tue 20:27:27
// https://neoj.sprout.tw/problem/410/
// TLE
#include<bits/stdc++.h>
using namespace std;
vector<vector<bool>>mark,pre;
int n;
void initialize(int n) {
    ::n = n;
    mark = pre = vector<vector<bool>>(n,vector<bool>(n));
    return;
}
int hasEdge(int a, int b) {
    if(mark.at(a).at(b)) return 0;
    if(pre.at(a).at(b)) return 1;
    vector<bool>mk(n);
    queue<int>q;
    q.emplace(0);
    while(!q.empty()) {
        int now = q.front();q.pop();
        if(mk.at(now)) continue;
        mk.at(now) = 1;
        for(int i = 0;i<n;i++) {
            if((now == a && i == b) || (now == b && i == a)) continue;
            if(!mark.at(now).at(i) && !mk.at(i)) q.emplace(i);
        }
    }
    for(int i = 0;i<n;i++) {
        if(!mk.at(i)) return pre.at(a).at(b) = pre.at(b).at(a) = 1,1;
    }
    mark.at(a).at(b) = mark.at(b).at(a) = 1;
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    initialize(n);
    int a,b;
    while(cin>>a>>b) {
        cout<<(hasEdge(a,b) == 0 ? "False" : "True")<<"\n";
    }
    return 0;
}