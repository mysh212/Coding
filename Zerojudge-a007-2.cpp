// Author : ysh
// 06/23/2022 Thu 14:24:14.87
#include<bits/stdc++.h>
using namespace std;
inline void pt(bool);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<bool>f(46341);
    vector<int>prime;
    for(int i = 2;i<46341;i++) {
        if(!f[i]) {
            prime.push_back(i);
            for(int j = i * i;j<46341;j+=i) {
                f[j] = 1;
            }
        }
    }
    int m;
    while(cin>>m) {
        if(m <= 46341) {
            pt(!f[m]);
            continue;
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
        pt(!c);
    }
    return 0;
}
inline void pt(bool x) {
    cout<<(x ? "質數" : "非質數")<<"\n";
    return;
}
