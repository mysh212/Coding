// Author : ysh
// 03/06/2022 Sun 12:16:13.32
// https://judge.tcirc.tw/ShowProblem?problemid=d043
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    deque<int>a(n),b(n);
    for(int &i : a) {
        cin>>i;
    }
    for(int &i : b) {
        cin>>i;
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans = 0;
    while(!a.empty()) {
        if(a.back() < b.back()) {
            ans++;
            a.pop_back();b.pop_back();
        } else {
            a.pop_back();b.pop_front();
        }
    }
    cout<<ans;
    return 0;
}