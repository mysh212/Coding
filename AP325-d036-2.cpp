// Author : ysh
// 09/09/2022 Fri 12:42:08.52
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n>>n;
    vector<int>f(n);
    map<int,int>m;
    int t = 0;
    for(int &i : f) {
        cin>>i;
        if(m.find(i) == m.end()) m.insert({i,t++});
        i = m.find(i)->second;
    }
    function<int(int,int)> check = [&] (int l,int r) {
        if(((r - l) + 1) < t) return 0;
        int mid = (l + r) >> 1;
        auto ll = check(l,mid);
        auto rr = check(mid + 1,r);
        int ans = ll + rr;
        int now = mid;
        vector<bool>mark(t);
        int m = 0;
        while(now >= l) {
            if(mark.at(f.at(now))) break;
            mark.at(f.at(now)) = 1;
            m++;
            now--;
        }
        now++;
        int nr = mid;
        while(now <= mid && nr < r) {
            nr++;
            // debug(l,r,mid,now,nr);
            if(mark.at(f.at(nr))) {
                while(mark.at(f.at(nr)) && now < nr) {
                    // debug(now,nr,m);
                    mark.at(f.at(now)) = 0;
                    m--;
                    now++;
                }
                mark.at(f.at(nr)) = 1;
                m++;
                if(m == t && now <= mid) {
                    debug(l,r,mid,now,nr);
                    ans++;
                }
                continue;
            }
            mark.at(f.at(nr)) = 1;
            m++;
            if(m == t) {
                    debug(l,r,mid,now,nr);
                ans++;
            }
        }
        return ans;
    };
    cout<<check(0,n - 1);
    return 0;
}