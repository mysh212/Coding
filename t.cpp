// Author : ysh
// 2023/07/25 Tue 17:27:40
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

    int n;cin>>n;
    vector<int>f(n),v(n);
    for(int &i : f) cin>>i;
    color = vector<int>(n + 1);
    iota(color.begin(),color.end(),0);

    int m;cin>>m;
    while(m--) {
        short a;cin>>a;
        if(a == 1) {
            int a,b;cin>>a>>b;
            a--;
            while(b != 0 && a != n) {
                if(f.at(a) - v.at(a) < b) b = b - (f.at(a) - v.at(a)),v.at(a) = f.at(a),mg(a,a + 1);
                else v.at(a) = v.at(a) + b,b = 0;
                a = ff(a);
            }
        }
        if(a == 2) {
            int a;cin>>a;
            cout<<v.at(a - 1)<<"\n";
        }
    }
    return 0;
}