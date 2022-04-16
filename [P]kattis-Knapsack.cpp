// Author : ysh
// 04/06/2022 Wed  8:11:20.57
#include<bits/stdc++.h>
using namespace std;
#define p system("pause");
int b;
int main() {
    // freopen("0.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>b>>n) {
        // p
        // printf("{%d %d}\n",b,n);
        vector<pair<int,int>>f(n + 1); // (value,V)
        for(int i = 1;i<=n;i++) {
            cin>>f[i].first>>f[i].second;
        }
        // for(int i = 1;i<=n;i++) {
        //     cout<<f[i].first<<" "<<f[i].second<<"\n";
        // }
        int c[n+1][b+1] = {};
        pair<int,int> d[n+1][b+1] = {};
        for(int i = 1;i<=b;i++) {
            if(f[1].second <= i) {
                c[1][i] = f[1].first;
                d[1][i] = {1,i};
            }
        }
        bool yes = 0;
        for(int i = 2;i<=n;i++) {
            for(int j = 1;j<=b;j++) {
                if(j - f[i].second >= 0) {
                    if(c[i - 1][j] >= c[i - 1][j - f[i].second] + f[i].first) {
                        c[i][j] = c[i - 1][j];
                        d[i][j] = d[i - 1][j];
                        if(c[i][j] == 0) d[i][j] = {i,0};
                        yes = 0;
                    } else {
                        c[i][j] = c[i - 1][j - f[i].second] + f[i].first;
                        d[i][j] = {i - 1,j - f[i].second};
                        if(c[i - 1][j - f[i].second] == 0) d[i][j] = {i,0};
                        yes = 1;
                    }
                    //c[i][j] = max(c[i - 1][j],c[i - 1][j - f[i].second] + f[i].first);
                } else {
                    c[i][j] = c[i - 1][j];
                    d[i][j] = d[i - 1][j];
                    if(c[i][j] == 0) d[i][j] = {i,0};
                    yes = 0;
                }
            }
        }
        int x = n,y = b;
        // for(int i = 1;i<=n;i++) {
        //     for(int j = 1;j<=b;j++) {
        //         cerr<<"{ "<<c[i][j]<<" }\t";
        //     }
        //     cerr<<"\n";
        // }
        // for(int i = 1;i<=n;i++) {
        //     for(int j = 1;j<=b;j++) {
        //         cerr<<"{ "<<d[i][j].first<<","<<d[i][j].second<<" }\t";
        //     }
        //     cerr<<"\n";
        // }
        stack<int>q;
        if(yes) q.push(n);
        while(1) {
            int xx = d[x][y].first;
            int yy = d[x][y].second;
            if(yy == 0) {
                break;
            }
            if(xx == 1) {
                q.push(1);
                break;
            }
            q.push(xx);
            x = xx;y = yy;
        }
        cout<<q.size()<<"\n";
        while(!q.empty()) {
            cout<<q.top() - 1<<" ";q.pop();
        }
        cout<<"\n";
    }
    return 0;
}