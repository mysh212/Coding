// Author : ysh
// 06/26/2022 Sun 12:14:10.59
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

inline void pt(bool);
#define int long long
#define MAX 100000
vector<bool>f(MAX);
vector<int>prime;
// #define int long long
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

    class box{
        public:
        int toint(char x) {
            return (int) (x - '0');
        }
        int operator()(char x) {
            return toint(x);
        }
    }toint;
    init();
    // int n;
    // while(cin>>n) {
    //     cout<<n<<" "<<(int) check(n)<<"\n";
    // }
    // return 0;
    string a;
    while(cin>>a) {
        int tmp = 0;
        queue<int>q;
        for(char i : a) {
            debug(tmp);
            int now = tmp * 10 + toint(i);
            tmp = now;
            if(check(now)) {
                q.push(now);
                tmp = 0;
            }
        }
        cout<<q.size()<<"\n";
        while(!q.empty()) {
            cout<<q.front()<<"\n";q.pop();
        }
        cout<<"\n";
    }
    return 0;
}