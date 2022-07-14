// Author : ysh
// 07/08/2022 Fri 14:04:07
#include<bits/stdc++.h>
using namespace std;
int check(int,int);
set<int>s;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    for(int i = 0;i<a;i++) {
        int tmp;cin>>tmp;
        s.insert(tmp);
    }
    cout<<check(0,b);
    return 0;
}
int check(int l,int r) {
    printf("[%d %d]\n",l,r);
    assert(l <= r);
    double mid = (l + r) / 2;
    auto found = s.lower_bound(mid);
    auto pv = prev(found);
    set<int>::iterator rf;
    for(int i = 0;i<1;i++) {
        if(found == s.end() || *found >= r) {
            if(pv == --s.begin() || *pv <= l) {
                return 0;
            }
            rf = pv;
            break;
        }
        if(pv == --s.begin() || *pv <= l) {
            rf = found;
            break;
        }
        if((*found - mid) >= (mid - *pv)) {
            rf = pv;
            break;
        }
        rf = found;
        break;
    }
    return check(*rf,r) + check(l,*rf) + (r - l);
}