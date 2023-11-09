// Author : ysh
// 2023/09/22 Fri 00:20:22
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
        int a,b,c;cin>>a>>b>>c;
        vector<vector<int>>f(a);
        for(int i = 0;i<a;i++) {
            int a,b;cin>>a>>b;
            a--;b--;
            f.at(a).push_back(b);
            f.at(b).push_back(a);
        }

        vector<vector<int>>v(a);
        vector<int>re(a);
        vector<bool>mark(a);
        bool ok = 0;
        int tmp = c;
        int root = 0;
        function<void(int,int,bool)> check = [&] (int last,int x,bool c) {
            re.at(x) = last;
            if(x == tmp - 1) c = 1;
            if(mark.at(x) && c) ok = 1;
            if(mark.at(x)) return root = x,void();
            mark.at(x) = 1;
            for(int &i : f.at(x)) {
                if(i != last) {
                    check(x,i,c);
                }
            }
        };

        // int ans = 1;
        // int now = re.at(root);
        // debug(root,re);
        // while(now != root) ans++,now = re.at(now);
        // cout<<ans<<"\n";

        check(-1,b - 1,0);
        if(b == c) ok = 0;
        cout<<(ok ? "YES" : "NO")<<"\n";
    }
    return 0;
}