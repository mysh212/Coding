// Author : ysh
// 11/20/2022 Sun 22:44:10.51
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int check(int n,vector<int>&f) {
    vector<bool>mark(n),mk(n);
    vector<int>l(n),r(n);
    if(n == 1) return 1;
    for(int i = 0;i<n;i++) {
        l.at(i) = i - 1;
        r.at(i) = i + 1;
        if(i == 0) {
            l.at(i) = n - 1;
            if(f.at(1) == f.at(n - 1)) mark.at(0) = 1;
            continue;
        }
        if(i == n - 1) {
            r.at(i) = 0;
            if(f.at(0) == f.at(n - 2)) mark.at(n - 1) = 1;
            continue;
        }
        if(f.at(i - 1) == f.at(i + 1)) mark.at(i) = 1;
    }
    int ans = 0;
    for(int i = 0;i<n;i++) {
        debug(l);
        debug(r);
        bool c = 0;
        for(int j = 0;j<n;j++) {
            if(mk.at(j)) continue;
            if(l.at(j) == r.at(j)) return ans + 2;
            if(f.at(l.at(j)) != f.at(r.at(j))) {
                ans++;
                // printf("r.at(%d) = %d;\n",l.at(j),r.at(j));
                r.at(l.at(j)) = r.at(j);
                // printf("l.at(%d) = %d;\n",r.at(j),l.at(j));
                l.at(r.at(j)) = l.at(j);
                mk.at(j) = 1;
                c = 1;
                break;
            }
        }
        if(c) continue;
        if(!c) {
            for(int j = 0;j<n;j++) {
                cerr<<1;
                if(mk.at(j)) continue;
                if(l.at(j) == r.at(j)) return ans + 1;
                ans++;
                // if(r.at(j) == l.at(j)) 
                r.at(l.at(j)) = r.at(j);
                l.at(r.at(j)) = l.at(j);
                r.at(l.at(r.at(j))) = r.at(r.at(j));
                l.at(r.at(r.at(j))) = l.at(r.at(j));
                mk.at(j) = mk.at(r.at(j)) = 1;
                c = 1;
                break;
            }
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int m;cin>>m;
        vector<int>f(m);
        for(int &i : f) {
            cin>>i;
        }
        cout<<check(m,f)<<"\n";
    }
}