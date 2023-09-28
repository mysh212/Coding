// Author : ysh
// 2023/07/08 Sat 09:05:56
#include<bits/stdc++.h>
using namespace std;
void input(bitset<10>&s) {
    string a;cin>>a;
    int t = 0;
    for(char i : a) {
        if(i == '1') s.set(t);
        t++;
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        vector<bitset<10>>f(b),g(b);
        vector<int>v(b);
        bitset<10>pre;
        input(pre);
        for(int i = 0;i<b;i++) {
            cin>>v.at(i);
            input(f.at(i));
            input(g.at(i));
        }

        vector<vector<int>>d(b);
        queue<int>q;
    }
}