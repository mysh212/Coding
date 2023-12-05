// Author : ysh
// 2023/11/27 Mon 11:10:34
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int a,b,c;
vc<int>f;
bool check(int x) {
    int ans = 0;
    repo(&i,f) if(x >= (i + x + c) / (c + 1)) ans++;
    return ans <= b;
}
inline int ck(int l,int r) {
    if(l + 1 == r) return l;
    int mid = (l + r) >> 1;
    if(check(mid)) return ck(mid,r);
    return ck(l,mid);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b>>c;
    f = vc<int>(a);
    cin>>f;

    cout<<ck(0,*max_element(all(f)) + 1);
    return 0;
}