// Author : ysh
// 06/10/2022 Fri 13:38:31.07
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

    string tmp;
    int n;getline(cin,tmp);n = stoi(tmp);
    debug(n);
    while(n--) {
        string a;
        getline(cin,a);
        stringstream s;
        s << a;
        int b;
        deque<int>f;
        while(s >> b) {
            f.push_back(b);
        }
        f.pop_front();
        int mmax = f[0];
        int len = f.size();
        for(int i = 1;i < len;i++) {
            f[i] = max(f[i],f[i - 1] + f[i]);
            mmax = max(mmax,f[i]);
        }
        debug(f);
        cout<<mmax<<"\n";
    }
    return 0;
}