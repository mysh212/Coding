// Author : ysh
// 2025/07/15 Tue 13:46:16
// https://cses.fi/problemset/task/1713
#include<bits/stdc++.h>
using namespace std;
const int R = (int) 1e3 + 1;
bitset<R>s;
vector<int>prime;
inline void init() {
    s.set(0);s.set(1);
    for(int i = 2;i<R;i++) {
        if(!s.test(i)) prime.push_back(i);
        for(int j = i * i;j<R;j += i) {
            s.set(j);
        }
    }
    return;
}
inline int check(int x) {
    int ans = 1;
    for(int &i : prime) {
        int now = 0;
        while(x % i == 0) now++, x = x / i;
        ans = ans * (now + 1);
    }
    if(x != 1) ans = ans << 1;
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        cout<<check(n)<<"\n";
    }
    return 0;
}