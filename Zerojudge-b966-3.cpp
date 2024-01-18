// Author : ysh
// 2024/01/18 Thu 17:07:55
#include<bits/stdc++.h>
using namespace std;
const int R = int(1e7) + 1;
int n;
vector<bool>f;
#define left(i) ((i << 1) + 1)
#define right(i) ((i << 1) + 2)
void add(int l,int r,int t = 0,int nl = -1,int nr = -1) {
    if(nl == -1 && nr == -1) nl = 0,nr = n - 1;
    if(nl >= l && nr <= r) return f.at(t) = 1,void();
    if(nl > r || nr < l) return;
    int mid = (nl + nr) >> 1;
    add(l,r,left(t),nl,mid);
    add(l,r,right(t),mid + 1,nr);
    return;
}
int check(int t = 0,int l = -1,int r = -1) {
    if(l == -1 && r == -1) l = 0,r = n - 1;
    if(f.at(t)) return (r - l + 1);
    if(l == r) return (f.at(t) ? 1 : 0);
    int mid = (l + r) >> 1;
    return check(left(t),l,mid) + check(right(t),mid + 1,r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    f.resize(R << 2);
    ::n = R;

    while(n--) {
        int a,b;cin>>a>>b;
        add(a + 1,b);
    }
    cout<<check();
    return 0;
}