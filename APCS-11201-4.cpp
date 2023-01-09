// Author : ysh
// 01/08/2023 Sun 17:57:51.58
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

struct box{
    int x,y;
    box(int x = 0,int y = 0):
        x(x), y(y) {};
    inline bool operator<(const box a) const {
        return y > a.y;
    }
};
ostream& operator<<(ostream &a,box &b) {
    a << "[" << b.x << " " << b.y << "]\n";
    return a;
}
vector<box>f;
vector<int>mark,re;
vector<bool>disable;
int check(int x) {
    if(x == -1) return 0;
    if(disable.at(x)) return check(x - 1);
    if(mark.at(x) != 0) return mark.at(x);
    auto found = upper_bound(f.rbegin(),f.rend(),box(0,f.at(x).x));
    if(found == f.rend()) {
        int l = 1;
        int r = check(x - 1);
        if(l >= r) re.at(x) = -2;
        return mark.at(x) = max(1,r);
    }
    int l = check(f.rend() - found - 1) + 1;
    int r = check(x - 1);
    if(l >= r) re.at(x) = f.rend() - found - 1;
    return mark.at(x) = max(l,r);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,k;cin>>n>>k;
    f.resize(n);
    mark.resize(n);
    re.resize(n,-1);
    disable.resize(n);
    for(box &i : f) cin>>i.x;
    for(box &i : f) cin>>i.y;
    sort(f.rbegin(),f.rend());
    for(box &i : f) cout<<i;
    int ans = 0;
    for(int i = 0;i<k;i++) {
        ans = ans + check(n - 1);
        int now = n - 1;
        while(now != -1) {
            if(re.at(now) == -2) {
                disable.at(now) = 1;
                break;
            }
            if(re.at(now) == -1) {
                now--;
                continue;
            }
            disable.at(now) = 1;
            now = re.at(now);
        }
        debug(re);
        debug(mark);
        debug(disable);
        re = vector<int>(n,-1);
        mark = vector<int>(n);
    }
    cout<<ans;
    return 0;
}