// Author : ysh
// 2023/12/11 Mon 13:45:02
#include<bits/stdc++.h>
using namespace std;
#include<slow>
#include<fast>
const int R = int(1e4);
bitset<R + 1>s;
vector<int>prime;
void init() {
    re(i,2,R + 1) {
        if(s.test(i)) continue;
        prime.pb(i);
        re(j,i * i,R + 1,i) s.set(j);
    }
    return;
}
vc<pair<int,int>> check(int x) {
    vc<pair<int,int>>f;
    repo(&i,prime) {
        if(x == 1) break;
        int now = 0;
        while(x % i == 0) x = x / i,now++;
        if(now != 0) f.emplace_back(i,now);
    }
    if(x != 1) f.emplace_back(x,1);
    return f;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int n;cin>>n;
    bool c = 0;
    repo(&i,check(n)) {
        if(c) outs("*");
        if(i.second == 1) outs(i.first);
        else out(i.first),outt(^),outs(i.second);
        c = 1;
    }
    return 0;
}