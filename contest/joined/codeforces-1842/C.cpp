// Author : ysh
// 2023/06/24 Sat 22:32:49
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
        vector<int>f(n),re(n,-1),pre(n + 1,-1);
        int t = 0;
        for(int &i : f) {
            cin>>i;
            if(pre.at(i) != -1) re.at(t) = pre.at(i);
            pre.at(i) = t;
            t++;
        }
        debug(re,pre);

        vector<int>v(n);
        for(int i = 1;i<n;i++) {
            v.at(i) = max({v.at(i),v.at(i - 1)});
            if(re.at(i) == -1) continue;
            v.at(i) = max({v.at(i),v.at(re.at(i)) + (i - re.at(i)),(re.at(i) == 0 ? i + 1 : v.at(re.at(i) - 1) + (i - re.at(i) + 1))});
        }
        debug(v);
        cout<<v.at(n - 1)<<"\n";
    }
    return 0;
}