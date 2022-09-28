// Author : ysh
// 09/28/2022 Wed 11:02:47.51
// https://judge.tcirc.tw/ShowProblem?problemid=d101
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
vector<int>r;
multiset<int>s;
int t = 0;
inline int ff(int n) {
    if(f.at(n) == -1) {
        s.insert(1);
        return f.at(n) = n;
    }
    if(f.at(n) == n) return n;
    return f.at(n) = ff(f.at(n));
}
inline void mg(int a,int b) {
    f.at(ff(a)) = ff(b);
    s.erase(s.lower_bound(r.at(ff(a))));
    s.erase(s.lower_bound(r.at(ff(b))));
    r.at(ff(b)) += r.at(ff(a));
    r.at(ff(a)) = 0;
    s.insert(r.at(ff(b)));
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    f.resize(a,-1);
    r.resize(a,-1);
    for(int i = 0;i<a;i++) {
        int tmp;cin>>tmp;
        if(i != 0 && tmp == 1 && f[i - 1] != -1) {
            mg(i - 1,i);
        }
    }
    int mmax = INT_MIN;
    int mmin = INT_MAX;
    int mmaxa = 0;
    int mmina = 0;
    for(int i = 0;i<b;i++) {
        int tmp;cin>>tmp;tmp--;
        if(tmp != 0 && f[tmp - 1] != -1) {
            mg(tmp - 1,tmp);
        }
        if(tmp != a - 1 && f[tmp + 1] != -1) {
            mg(tmp + 1,tmp);
        }
        mmax = max(mmax,*prev(s.end()));
        mmin = min(mmin,*s.begin());
        mmaxa += mmax;
        mmina += mmin;
    }
    cout<<mmaxa<<"\n"<<mmina;
    return 0;
}