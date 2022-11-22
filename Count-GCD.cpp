// Author : ysh
// 11/22/2022 Tue 11:17:46.40
// https://codeforces.com/problemset/problem/1750/D
#include<bits/stdc++.h>
using namespace std;
const int R = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        vector<int>f(a);
        int last = 0;
        bool c = 0;
        for(int &i : f) {
            cin>>i;
            if(last != 0) {
                if(last % i != 0) c = 1;
            }
            last = i;
        }
        if(c) {
            cout<<"0\n";
            continue;
        }
        vector<int>v;
        for(int i = 1;i<a;i++) {
            if(f.at(i - 1) == 1) continue;
            v.push_back((b / f.at(i)) - (b / f.at(i - 1)));
        }
        for(int i : v) cerr<<i<<" ";
        cerr<<"\n";
        long long ans = 1;
        for(int i : v) {
            ans = (ans * 1LL * i) % R;
        }
        cout<<ans<<"\n";
    }
    return 0;
}