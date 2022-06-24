// Author : ysh
// 06/20/2022 Mon 17:09:49.37
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
vector<vector<bool>>r(201,vector<bool>(201));
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    f.resize(n);
    map<int,int>m;
    for(int i = 0;i<n;i++) {
        cin>>f[i];
        f[i] = f[i];
    }
    // reverse(f.begin(),f.end());
    for(int i = 0;i<n;i++) {
        if(m.find(f[i]) == m.end()) {
            m.insert({f[i],i});
        }
    }
    // for(auto i : m) {
    //     cout<<i.first<<" "<<i.second<<"\n";
    // }
    // m.insert({-1,-1});
    vector<int>g;
    for(int i = 0;i<n;i++) {
        auto found = lower_bound(g.begin(),g.end(),f[i]);
        if(found == g.end()) {
            g.push_back(f[i]);
            r[i][n] = 1;
            int tmp;
            if(found - g.begin() > 0) {
                tmp = g[found - g.begin() - 1];
                if(g.size() >= 2) {
                    r[m[tmp]][i] = 1;
                    // printf("r[m[%d]+1][%d] = r[m[%d]+1][%d] = 1\n",tmp,i,m[tmp],i);
                }
            }
        } else {
            *found = f[i];
            r[m[*prev(found)]][i] = 1;
            // printf("r[m[%d]+1][%d] = r[m[%d]+1][%d] = 1\n",*prev(found),i,m[*prev(found)],i);
        } 
    }
    for(int i = -1;i<10;i++) {
        if(i == -1) {
            cout<<"  0 1 2 3 4 5 6 7 8 9\n";
            continue;
        }
        cout<<i<<" ";
        for(int j = 0;j<10;j++) {
            
            cout<<(int) r[i][j]<<" \n"[j == 9];
        }
    }
    int x,y;y = 200;x = n;
    vector<int>q;
    int last = -1;
    while(1) {
        // cerr<<x<<" "<<y<<"\n";
        if(r[y][x]) {
            if(last != y) {
                // printf("(%d,%d) q.push(%d)\n",x,y,y);
                x = y;
                q.push_back(y);
                last = y;
                // x--;
            } else {
                x--;
            }
        } else {
            y--;
        }
        if(x <= 0) {
            if(x == 0) q.push_back(f[0]);
            break;
        }
        if(y == -1) break;
    }
    while(!q.empty()) {
        if(q.back() != n) cout<<-f[q.back()]<<" ";q.pop_back();
    }
    cout<<"\n";
    cout<<g.size();
    return 0;
}
int check(int x,int y,int t) {
        int last;
        if(r[y][x]) {
            while(y != 0) {
                
            }
        } else {
            y--;
        }
}