// Author : ysh
// 05/05/2023 Fri 22:59:27.94
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
    for(int i = 0;i<n;i++) {
        int r;cin>>r;
        vector<int>f(r);
        for(int &i : f) {
            cin>>i;
        }
        vector<int>tmp;
        for(int i = 0,len = (r >> 1) + ((int) (r & 1));i<len;i++) {
            if(abs(f.at(i) - f.at(r - i - 1)) != 0) tmp.push_back(abs(f.at(i) - f.at(r - i - 1)));
        }
        if(tmp.empty()) {
            cout<<0<<"\n";
            continue;
        }
        int now = tmp.at(0);
        for(int &i : tmp) {
            now = __gcd(now,i);
        }
        cout<<now<<"\n";
        // debug(tmp);
    }
}