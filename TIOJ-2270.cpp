// Author : ysh
// 10/07/2022 Fri  9:19:10.82
// https://tioj.ck.tp.edu.tw/problems/2270
#include<bits/stdc++.h>
#include<iomanip>
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

using namespace std;
vector<vector<int>>f;
int re = 0;
int ans = 1;
bool bk = 0;
#define int long long
int ch(int a,int b) {
    // cerr<<a<<" "<<b<<"\n";
    // H YA~
    if(a < b) swap(a,b);
    int tmp = a;
    a++;
    a = a + b - 1;
    long long r = 1;
    for(int i = 0;i<b;i++) {
        r = r * (a--);
    }
    for(int i = 1;i<=b;i++) {
        r = r / (i);
    }
    // printf("C(%d,%d) = %d\n",tmp,b,r);
    return r;
}
vector<bool>mark;
int check(int x) {
    if(bk) return -1;
    mark.at(x) = 1;
    if(re-- < 0) return -1;
    queue<int>q;
    for(int i : f.at(x)) {
        q.push(check(i));
    }
    if(bk) return -1;
    if(q.empty()) return 1;
    while(q.size() >= 2) {
        int aa = q.front();q.pop();
        int bb = q.front();q.pop();
        ans = ans * ch(aa,bb);
        if(ans > 100) {
            bk = 1;
            return -1;
        }
        q.push(aa + bb);
    }
    return q.front() + 1;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    f.resize(a);
    mark.resize(a);
    re = max(a,b << 2);
    vector<int>in(a);
    for(int i = 0;i<b;i++) {
        int a,b;char c;
        cin>>a>>c>>b;
        a--;b--;
        if(c == '>') {
            f.at(b).push_back(a);
            in.at(a)++;
            continue;
        }
        f.at(a).push_back(b);
        in.at(b)++;
    }
    // int r = 0;
    // for(auto i : f) {
    //     r++;
    //     for(int j : i) {
    //         cerr<<r<<" "<<j + 1<<"\n";
    //     }
    // }
    queue<int>q;
    for(int i = 0;i<a;i++) {
        if(in.at(i) == 0) {
            debug(i);
            q.emplace(check(i));
        }
    }
    if(re < 0) {
        cout<<-1;
        return 0;
    }
    if(bk) {
        cout<<0;
        return 0;
    }
    if(q.empty()) {
        cout<<-1;
        return 0;
    }
    while(q.size() >= 2) {
        int aa = q.front();q.pop();
        int bb = q.front();q.pop();
        ans = ans * ch(aa,bb);
        if(ans > 100) {
            cout<<0;
            return 0;
        }
        q.push(aa + bb);
    }
    cout<<fixed<<setprecision(10)<<100.0 / ans;
    // for(int i = 0;i<a;i++) {
    //     cout<<" "<<check(i);
    // }
    // cout<<" "<<ans;
    return 0;
}
