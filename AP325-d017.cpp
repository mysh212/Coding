// Author : ysh
// 12/09/2022 Fri 14:52:59.10
// https://judge.tcirc.tw/ShowProblem?problemid=d017
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

vector<int>mark({1,1});
int a,b;
int gcd(int x,int y,int &a,int &b) {
    if(y == 0) {
        a = 0;b = 1;
        return x;
    }
    int ans = gcd(y,x % y,a,b);
    int tmp = a;
    a = b - (x / y) * a;
    b = tmp;
    debug(x,y,a,b);
    return ans;
}
int check(int x) {
    int a,b;a = 0,b = 1;
    gcd(::b,x,a,b);
    return (a % ::b + ::b) % ::b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;
    // mark.resize(b + 1);
    // for(int i = 2;i<=b;i++) {
    //     mark.at(i) = b - (((b / i) * mark.at(b % i)) % b);
    // }
    while(a--) {
        int tmp;cin>>tmp;
        // if(mark.size() - 1 < tmp) mark.resize(tmp + 1);
        cout<<check(tmp)<<" ";
    }
    return 0;
}