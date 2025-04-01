// Author : ysh
// 2024/12/03 Tue 18:53:46
// https://judge.citrc.tw/problem/63
#include<bits/stdc++.h>
using namespace std;
int a,b;
vector<int>f;
bool check(long long x) {
    int p = 0;
    int ans = 0;
    for(int i = 0;i<a;i++) {
        while(p != a && 1LL * f.at(i) + f.at(p) <= x) p++;
        ans = ans + (a - p);
    }
    return ans <= b - 1;
}
inline int ck(long long l,long long r) {
    if(l == r) return l;
    long long mid = (l + r) >> 1;

    if(check(mid)) return ck(l, mid);
    return ck(mid + 1,r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    f = vector<int>(a);
    for(int &i : f) cin>>i;

    sort(f.begin(),f.end());

    long long pre = accumulate(f.begin(),f.end(),0);
    cout<<ck(-pre,pre);
    return 0;
}