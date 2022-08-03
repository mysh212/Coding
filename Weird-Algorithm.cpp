// Author : ysh
// 08/03/2022 Wed  9:08:01
// https://cses.fi/problemset/task/1068
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    class box{
        public:
        void check(int a) {
            cout<<a<<" ";
            if(a == 1) return;
            if(a & 1) check((a * 3) + 1);
            else check(a >> 1);
            return;
        }
    }c;
    int n;cin>>n;
    box().check(n);
    return 0;
}
