// Author : ysh
// 06/14/2022 Tue 23:33:07.30
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a;cin>>a;
        vector<int>m(10);
        for(int i = 0;i<a;i++) {
            int tmp;cin>>tmp;
            m.at(tmp % 10)++;
        }
        bool c = 0;
        debug(m);
        for(int i = 0;i <= 9;i++) {
            for(int j = i;j <= 9;j++) {
                int k = 23 - (i + j);
                if(k >= 10 || k < 0) continue;
                m[i]--;m[j]--;m[k]--;
                if(m[i] >= 0 && m[j] >= 0 && m[k] >= 0) {
                    debug(i,j,k);
                    cout<<"YES\n";
                    c = 1;
                    break;
                }
                m[i]++;m[j]++;m[k]++;
                if(c) break;
            }
            if(c) break;
        }
        if(c) continue;
        for(int i = 0;i <= 9;i++) {
            for(int j = i;j <= 9;j++) {
                int k = 13 - (i + j);
                if(k >= 10 || k < 0) continue;
                m[i]--;m[j]--;m[k]--;
                if(m[i] >= 0 && m[j] >= 0 && m[k] >= 0) {
                    debug(i,j,k);
                    cout<<"YES\n";
                    c = 1;
                    break;
                }
                m[i]++;m[j]++;m[k]++;
                if(c) break;
            }
            if(c) break;
        }
        if(c) continue;
        for(int i = 0;i <= 3;i++) {
            for(int j = i;j <= 3;j++) {
                int k = 3 - (i + j);
                if(k >= 10 || k < 0) continue;
                m[i]--;m[j]--;m[k]--;
                if(m[i] >= 0 && m[j] >= 0 && m[k] >= 0) {
                    debug(i,j,k);
                    cout<<"YES\n";
                    c = 1;
                    break;
                }
                m[i]++;m[j]++;m[k]++;
                if(c) break;
            }
            if(c) break;
        }
        if(c) continue;
        cout<<"NO\n";
    }
    return 0;
}