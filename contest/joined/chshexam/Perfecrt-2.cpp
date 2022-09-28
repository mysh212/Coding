#include<bits/stdc++.h>
using namespace std;
#define bigger "abundant\n"
#define equal "perfect\n"
#define smaller "deficient\n"
#define int long long
bitset<1006>s;
vector<int>prime;
int nnn;
vector<int>now(169);
int carry = 0;
inline void init() {
    for(int i = 2;i<1005;i++) {
        if(!s.test(i)) {
            for(int j = i * i;j<1005;j = j + i) {
                s.set(j);
            }
            prime.push_back(i);
        }
    }
}
inline void check(int n) {
    for(int i = 0;i<168;i++) {
        while(n % prime[i] == 0) {
            n = n / prime[i];
            now[i]++;
        }
    }
    if(n != 1) {
        carry = n;
    }
    return;
}
inline int ff(int a,int b) {
    if(b == 1) return a;
    int tmp = ff(a,b >> 1);
    if(b & 1) return tmp * tmp * a;
    return tmp * tmp;
}
inline int fast(int a,int b) {
    return (ff(a,b + 1) - 1) / (a - 1);
}
signed main() {
    //freopen("1","r",stdin);
    //freopen("1.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f(n);
    s.set(0);
    s.set(1);
    init();
    //for(int i : prime) cout<<i<<" ";
    for(int &i : f) {
        cin>>i;
        int r = i << 1;
        now.clear();
        now.resize(169);
        carry = 0;
        check(i);
        /*
        for(int i = 0;i<168;i++) {
            if(now[i] != 0) cerr<<prime[i]<<" "<<now[i]<<"\n";
        }
        cout<<carry<<" ";
        */
        int ans = 1;
        for(int i = 0;i<169;i++) {
            if(now.at(i) != 0) {
                int tmp = fast(prime[i],now.at(i));
                ans = ans * tmp;
            }
        }
        if(carry != 0) ans = ans * (carry + 1);
        if(ans > r) cout<<bigger;
        if(ans == r) cout<<equal;
        if(ans < r) cout<<smaller;
    }
    return 0;
}
