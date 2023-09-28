// Author : ysh
// 05/05/2023 Fri 23:15:29.28
#include<bits/stdc++.h>
using namespace std;
vector<int>prime;
bitset<(int) 1e3>s;
void init() {
    for(int i = 2;i<(int) 1e3;i++) {
        if(s.test(i)) continue;
        prime.push_back(i);
        for(int j = i * i;j<(int) 1e3;j = j + i) {
            s.set(j);
        }
    }
    return;
}
bool check(int a,int b) {
    if(b >= a && a != 1) return 0;
    for(int i = 0,len = prime.size();i<len && prime.at(i) <= b;i++) {
        if(a % prime.at(i) == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        cout<<(check(a,b) ? "YES\n" : "NO\n");
    }
    return 0;
}