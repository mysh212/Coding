// Author : ysh
// 12/07/2022 Wed 16:15:54.37
// https://codeforces.com/problemset/problem/1759/G
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

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<bool>mark(n + 1);
        vector<pair<int,int>>f;
        bool bk = 0;
        for(int i = 0;i<n;i = i + 2) {
            int tmp;cin>>tmp;
            if(tmp > n || tmp <= 0) bk = 1;
            if(!bk) {
                if(mark.at(tmp)) bk = 1;
                f.push_back({tmp,0});
                mark.at(tmp) = 1;
            }
        }
        if(bk) {
            cout<<-1<<"\n";
            continue;
        }
        set<int,greater<int>>s;
        int l = 0;
        for(int i = 1;i<=n;i++) {
            if(!mark.at(i)) {
                s.insert(i);
                // int &now = f.at(l++);
                // if(now > i) cout<<i<<" "<<now<<" ";
                // else cout<<now<<" "<<i<<" ";
            }
        }
        for(int i = (n >> 1) - 1;i>=0;i--) {
            debug(s);
            auto &now = f.at(i);
            auto found = s.lower_bound(now.first);
            if(found == s.end()) {
                cout<<"-1\n";
                bk = 1;
                break;
            }
            now.second = *found;
            s.erase(*found);
            debug(now,*found);
        }
        if(bk) continue;
        for(auto &i : f) {
            cout<<i.second<<" "<<i.first<<" ";
        }
        cout<<"\n";
    }
    return 0;
}