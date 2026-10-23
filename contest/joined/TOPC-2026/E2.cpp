// Author : ysh
// 2026/09/19 Sat 10:47:24
#include<bits/stdc++.h>
using namespace std;
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<vector<int>>f(n, vector<int>(n)), color(n, vector<int>(n, 0));
    for(auto &i : f) for(int &j : i) cin>>j, j--;

    vector<pair<int, int>>mark(n * n);

    for(int i = 0;i<n;i++) {
        for(int j = 0;j<n;j++) {
            mark.at(f.at(i).at(j)) = make_pair(i, j);
        }
    }
    // debug(mark);

    for(int i = 0, len = n * n; i < len; i++) {
        int ox = i / n;
        int oy = i % n;

        auto [nx, ny] = mark.at(i);

        if(ox != nx && oy != ny) goto no;
        if(ox == nx && oy == ny) continue;

        if(ox == nx) color.at(nx).at(ny) = 1;
        else color.at(nx).at(ny) = -1;

        debug(i, ox, nx, oy, ny);
    }
    // debug(color);
    // debug(mark);

    for(int k = 0;k<5;k++) for(int i = 0, len = n * n; i < len; i++) {
        int ox = i / n;
        int oy = i % n;

        auto [nx, ny] = mark.at(i);

        if(ox == nx && oy == ny) continue;

        bool set = ox == nx;
        int l = (set ? min(oy, ny) : min(ox, nx));
        int r = (set ? max(oy, ny) : max(ox, nx));
        for(int k = l;k<=r;k++) {
            int nnx = (set ? ox : k);
            int nny = (set ? k : oy);

            // debug(color);

            if((color.at(nnx).at(nny)) == set * 2) goto no;
            if(color.at(nnx).at(nny) == 0) color.at(nnx).at(nny) = -2 * (set ? 1 : -1);
        }
    }
    debug("1 passed");
    debug(color);
    
    for(int i = 0;i<n;i++) {
        // if(abs(color.at()))
        debug(i);
        
        vector<int>pre;
        // for(int j = 0;j<n;j++) if(color.at(i).at(j) < 0) pre.push_back(f.at(i).at(j));
        // if(!is_sorted(pre.begin(), pre.end())) goto no;
        pre.clear();
        for(int j = 0;j<n;j++) if(color.at(i).at(j) > 0) pre.push_back(f.at(i).at(j));
        if(!is_sorted(pre.begin(), pre.end())) goto no;
    }
    debug("2 passed");

    for(int i = 0;i<n;i++) {
        vector<int>pre;
        for(int j = 0;j<n;j++) if(color.at(j).at(i) < 0) pre.push_back(f.at(j).at(i));
        if(!is_sorted(pre.begin(), pre.end())) goto no;
        pre.clear();
        // for(int j = 0;j<n;j++) if(color.at(j).at(i) > 0) pre.push_back(f.at(j).at(i));
        // if(!is_sorted(pre.begin(), pre.end())) goto no;
    }

    yes:
    cout<<"Yes";
    return 0;

    no:
    cout<<"No";
    return 0;
}