// Author : ysh
// 06/30/2022 Thu 12:37:20.38
#include<bits/stdc++.h>
using namespace std;
#define MAX 10001
vector<bool>f(MAX);
vector<int>prime;
#define int long long
int check(int m) {
        if(m <= MAX) {
            return !f[m];
        }
        bool c = 0;
        int mmax = (int) sqrt(m) + 1;
        for(int i : prime) {
            if(i > mmax) break;
            if(m % i == 0) {
                c = 1;
                break;
            }
        }
        return !c;
}
void init() {
    f[0] = 1;
    f[1] = 1;
    for(int i = 2;i<MAX;i++) {
        if(!f[i]) {
            prime.push_back(i);
            for(int j = i * i;j<MAX;j+=i) {
                f[j] = 1;
            }
        }
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int a,b;
    while(cin>>a>>b) {
        int ans = 0;
        for(int i = a;i<=b;i++) {
            if(check(i)) ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}