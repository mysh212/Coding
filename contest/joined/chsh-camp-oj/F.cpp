// Author : ysh
// 08/15/2022 Mon 12:59:35.46
// https://cses.fi/problemset/task/1669
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>f;
vector<int>mark;
bool c = 0;
int t = 0;
int ff = 0;
queue<int>q;
bool check(int n,int r = 1) {
    if(mark.at(n) != 0) {
        if(r - mark.at(n) >= 3) {
            ff = n;
            q.push(n);
            return 1;
        }
        return 0;
    }
    mark.at(n) = r;
    // if(n == t && c && r >= 4) {
    //     q.push(n);
    //     return 1;
    // }
    c = 1;
    for(int i : f.at(n)) {
        if(check(i,r + 1)) {
            if(c) q.push(n);
            if(n == ff) {
                c = 0;
            }
            return 1;
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int a,b;cin>>a>>b;
    f.resize(a,vector<int>());
    mark.resize(a);
    for(int i = 0;i<b;i++) {
        int tmpa,tmpb;cin>>tmpa>>tmpb;
        tmpa--;tmpb--;
        f.at(tmpa).push_back(tmpb);
        f.at(tmpb).push_back(tmpa);
    }
    for(int i = 0;i<a;i++) {
        // mark.clear();
        // mark.resize(a);
        c = 0;
        t = i;
        if(check(i)) {
            cout<<"YES\n";
            cout<<q.size()<<"\n";
            while(!q.empty()) {
                cout<<q.front() + 1<<" ";q.pop();
            }
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}