// Author : ysh
// 07/17/2022 Sun 12:49:37
// https://judge.tcirc.tw/ShowProblem?problemid=d034
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a;cin>>a;
    map<int,int>m;
    queue<int>q;
    vector<int>f(a);
    for(int &i : f) {
        cin>>i;
        m.insert({i,0});
    }
    int all = m.size();
    int now = 0;
    int l = 0;
    int mmin = INT_MAX;
    for(int i : f) {
        q.push(i);
        m[i]++;
        l++;
        if(m[i] == 1) {
            now++;
        }
        // cout<<now<<" "<<l<<"\n";
        while(now == all) {
            mmin = min(mmin,l);
            int left = q.front();q.pop();
            m[left]--;
            if(m[left] == 0) {
                now--;
            }
            l--;
            if(now == all) mmin = min(mmin,l);
        }
    }
    cout<<mmin;
    return 0;
}