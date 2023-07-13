// Author : ysh
// 2023/07/07 Fri 16:59:57
#include<bits/stdc++.h>
using namespace std;
vector<int>color;
int ff(int x) {
    if(color.at(x) == x) return x;
    return color.at(x) = ff(color.at(x));
}
void mg(int a,int b) {
    color.at(ff(a)) = ff(b);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,b;cin>>n>>b;
    color.resize(n << 1);
    iota(color.begin(),color.end(),0);

    while(b--) {
        int a,b;cin>>a>>b;
        a--;b--;
        mg(a + n,b);
        mg(a,b + n);
        if(ff(a) == ff(b)) {
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}