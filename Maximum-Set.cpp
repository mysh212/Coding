// Author : ysh
// 03/01/2023 Wed 11:51:46.76
// https://codeforces.com/contest/1796/problem/C
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

vector<vector<int>>mark;
const int MAX = 1000;
vector<int>prime;
bitset<MAX>notprime;
void init() {
    for(int i = 2;i<MAX;i++) {
        if(notprime.test(i)) continue;
        prime.push_back(i);
        for(int j = i * i;j < MAX;j = j + i) {
            notprime.set(j);
        }
    }
    return;
}
vector<int>f((1e6) + 1);
void initspr() {
    f.at(1) = 1;
    for(int i = 2;i<=1e6;i++) {
        int now = 0;
        int r = i;
        for(int &j : prime) {
            while(r % j == 0) r = r / j,now = now + 1;
            if(r == 0) break;
        }
        f.at(i) = now + (r == 1 ? 0 : 1);
    }
    return;
}


int check(int a,int b,int l) {
    int ans = 0;
    cerr<<"\n";
    for(int j = a,r;;j++,r = ans) {
        for(int i = (1 << l);;i++) {
            if(j * i > b) break;
            if(f.at(i) >= l) {
                debug(a,b,j,i,f.at(i));
                ans++;
            }
        }
        if(ans == r) break;
    }
    return ans;
}


// int check(int a,int b,int n) {
//     if(a > b) return 0;
//     if(n == 0) return (a <= b ? 1 : 0);
//     if(mark.at(n).at(a) != 0) return mark.at(n).at(a);
//     int ans = 0;
//     for(int i = (a << 1);i<=b;i = i + a) {
//         ans = ans + check(i,b,n - 1);
//     }
//     return mark.at(n).at(a) = ans;
// }
// const int R = 998244353;
// int ck(int a,int b) {
//     long long ans = 0;
//     int l = __lg(b / a);
//     for(int i = a;i<=b;i++) {
//         mark = vector<vector<int>>(l + 1,vector<int>(b + 1));
//         int tmp = check(i,b,l);
//         if(tmp == 0) break;
//         ans = ans + tmp;
//     }
//     return ans % R;
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    initspr();

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        cout<<__lg(b / a) + 1<<" ";
        cout<<check(a,b,__lg(b / a))<<"\n";
    }
    return 0;
}