// Author : ysh
// 2026/11/05 Thu 16:48:04
#include<bits/stdc++.h>
using namespace std;
#include<slow>
const int xx[] = {0, 1, 0, -1};
const int yy[] = {1, 0, -1, 0};
const char pp[] = {'+', '-', '*', '/'};

#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;cin>>n>>m;
    vc<vc<char>>f(n, vc<char>(m));
    cin>>f;

    vc<vc<bool>>mark(n, vc<bool>(m));
    function<long long(int, int)> check = [&] (int x, int y) {
        if(mark.at(x).at(y)) exit(-1);
        mark.at(x).at(y) = 1;

        vector<long long>pre;
        bool op = 0;
        
        if(isdigit(f.at(x).at(y))) return 1LL * (f.at(x).at(y) & 15);
        re(k, 4) if(f.at(x).at(y) == pp[k]) op = 1;

        re(k, 4) {
            int nx = x + xx[k];
            int ny = y + yy[k];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if((f.at(nx).at(ny) == '.') || mark.at(nx).at(ny)) continue;

            if(!op) return check(nx, ny);
            else pre.push_back(check(nx, ny));
        }

        assert(pre.size() == 2);
        char opp = f.at(x).at(y);

        if(pre[1] > pre[0]) swap(pre[0], pre[1]);
        if(opp == '+') return pre[0] + pre[1];
        if(opp == '-') return pre[0] - pre[1];
        if(opp == '*') return pre[0] * pre[1];
        if(opp == '/') return pre[0] / pre[1];

        return -1LL;
    };

    re(i, n) re(j, m) if(f.at(i).at(j) == 'P') return out(check(i, j)), 0;

    return -1;
}