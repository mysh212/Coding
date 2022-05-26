// Author : ysh
// 05/08/2022 Sun 14:42:56.26
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a);
    for(int i = 0;i<a;i++) {
        cin>>f[i];
    }
    int n;cin>>n;
    while(n--) {
        int now = 0;
        cin>>now;
        if(now == 2) {
            int aa,bb;cin>>aa>>bb;
            map<int,int>c;
            for(int j = 0;j<bb;j++) {
                int tmpa,tmpb;
                cin>>tmpa>>tmpb;
                c.insert({tmpa,tmpb});
            }
            // vector<int>d(b);
            bool ck = 0;
            for(int i = aa - 1;i<a;i++) {
                auto found = c.find(f[i]);
                if(found != c.end()) {
                    c[i]--;
                    if(c[i] <= 0) {
                        c.erase(found);
                    }
                }
                if(c.empty()) {
                    cout<<i + 1<<"\n";
                    ck = 1;
                    break;
                }
            }
            if(!ck) cout<<"-1\n";
        }
        if(now == 1) {
            int tmpa,tmpb;cin>>tmpa>>tmpb;
            tmpa = tmpa - 1;
            f[tmpa] = tmpb;
            for(int i : f) cout<<i<<" ";
            cout<<"\n";
        }
    }
}