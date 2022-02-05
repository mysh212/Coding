// Author : ysh
// 02/05/2022 Sat 17:37:42.78
// http://choj.me/problem/00053
#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int> run(int a,int b,int ta,int tb,vector<bool> &f) {
    if(f.empty()) return {a,b};
    int na = (a * a - b * b)%1000000007;
    int nb = (a * b * 2)%1000000007;
    a=na;b=nb;
    int n = f.back();f.pop_back();
    if(n) {
        int na = (a * ta - b * tb)%1000000007;
        int nb = (b * ta + a * tb)%1000000007;
        a=na;b=nb;
    }
    return run(a,b,ta,tb,f);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b,c;cin>>a>>b>>c;
        vector<bool>f;
        int d = c;
        while(d != 0) {
            f.push_back(d & 1);
            d = d >> 1;
        }
        auto tmp = run(1,0,a,b,f);
        cout<<(tmp.first >= 0? tmp.first : tmp.first + 1000000007)<<" "<<(tmp.second >= 0? tmp.second : tmp.second + 1000000007)<<"\n";
    }
    return 0;
}