// Author : ysh
// 05/31/2022 Tue 14:33:40.91
// http://poj.org/problem?id=1703
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
void cc(int x,int y) {
    f[(ff(x))] = f[(ff(y))];
    return;
}
inline int ff(int x) {
    if(f[x] == -1) return f[x] = x;
    return f[x] = ff(f[x]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        f.resize(a + 1,-1);
        // iota(f.begin(),f.end(),0);
        for(int i = 0;i<b;i++) {
            string tmp;cin>>tmp;
            if(tmp == "A") {

            }
            if(tmp == "D") {
                
            }
        }
    }
}