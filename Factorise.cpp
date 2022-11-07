// Author : ysh
// 10/29/2022 Sat 17:29:51.86
// https://codeforces.com/contest/1740/problem/A
#include<bits/stdc++.h>
using namespace std;
#define MAX 500
vector<bool>f(MAX);
vector<int>prime;
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
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    int n;cin>>n;
    while(n--) {
        int m;cin>>m;
        for(int &i : prime) {
            if(!check(m + i)) {
                cout<<i<<"\n";
                break;
            }
        }
    }
    return 0;
}