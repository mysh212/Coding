// Author : ysh
// 10/14/2022 Fri  8:17:54.88
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

struct table{
    vector<vector<int>>f;
    int n;

    table(vector<int>&v) {
        this->n = v.size();
        // cerr<<n;
        f.resize(n,vector<int>(__lg(n) + 1));
        for(int i = 0;i<n;i++) {
            f[i][0] = v[i];
        }
        for(int i = 1;i<=__lg(n);i++) {
            for(int j = 0;j + (1 << i) < n;j++) {
                f[j][i] = min(f[j][i - 1],f[j + (1 << (i - 1))][i - 1]);
            }
        }
    }

    int get(int l,int r) {
        if(l > r) swap(l,r);
        int ll = __lg(r - l + 1);
        return min(f[l][ll],f[r - (1 << ll) + 1][ll]);
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<vector<int>>f(a);
    for(int i = 0;i<a;i++) {
        int tmp;
        while(cin>>tmp) {
            if(tmp == 0) break;
            f.at(i).push_back(tmp - 1);
        }
    }
    vector<bool>mark(a);
    // vector<int>mk,mre(a);
    vector<int>l;
    vector<int>re(a),fre(a);
    vector<int>level(a);
    vector<int>nowl(a,-1);
    function<void(int,int)> check = [&] (int x,int r) {
        if(mark.at(x)) return;
        mark.at(x) = 1;
        l.push_back(x);
        level.at(x) = r;
        fre.at(x) = l.size() - 1;
        for(int &i : f.at(x)) {
            check(i,r + 1);
            l.push_back(x);
        }
        re.at(x) = l.size() - 1;
        return;
    };
    // int ans = 0,fd = 0;
    function<int(int,int,int)> ck = [&] (int a,int b,int c) {
        // return min(abs(fre.at(b - 1) - re.at(a - 1)),abs(re.at(b - 1) - fre.at(a - 1)));
        a--;b--;
        return level[a] + level[b] - (level[c] << 1);
        // int r = 0;
        // int now = mre.at(c);
        // vector<int>v({-1});
        // int aa = -1,bb = -1;
        // // cerr<<a<<" "<<b<<"\n";
        // while(1) {
        //     debug(v,r,mk.at(now),aa,bb);
        //     assert(now < mk.size());
        //     if(bb == -1 && mk.at(now) == b) bb = r;
        //     if(aa == -1 && mk.at(now) == a) aa = r;
        //     if(aa != -1 && bb != -1) return aa + bb;
        //     if(mk.at(now) == v.back()) {
        //         v.pop_back();
        //         r--;
        //         now++;
        //         continue;
        //     }
        //     v.push_back(mk.at(now));
        //     r++;
        //     now++;
        // }
        // return 0;

        // queue<pair<int,int>>q;
        // int aa = -1,bb = -1;
        // q.emplace(c,0);
        // while(!q.empty()) {
        //     auto now = q.front();q.pop();
        //     int d = now.first;
        //     int r = now.second;
        //     if(d == a) aa = r;
        //     if(d == b) bb = r;
        //     if(aa != -1 && bb != -1) return aa + bb;
        //     for(int &i : f.at(d)) {
        //         q.emplace(i,r + 1);
        //     }
        // }
    };
    check(0,0);
    // debug(ll);
    table t = table(l);
    // for(int &i : l) cerr<<i<<" ";
    for(int i = 0;i<b;i++) {
        int a,b;cin>>a>>b;
        int tmp = t.get(re.at(a - 1),re.at(b - 1));
        cout<<tmp + 1<<" "<<ck(a,b,tmp)<<"\n";
    }
    return 0;
}