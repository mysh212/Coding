// Author : ysh
// 06/02/2022 Thu  9:51:09.34
// https://open.kattis.com/problems/knapsack
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    while(cin>>b>>a) {
        vector<int>p(a),v(a);
        for(int i = 0;i<a;i++) {
            int c,d;cin>>d>>c;
            p[i] = c;
            v[i] = d;
        }
        int w[b + 1] = {};
        bool mark[b + 1][a + 1] = {};
        for(int j = 0;j<a;j++) {
            for(int i = b;i>=1;i--) {
                if(p[j] <= i) {
                    if(i >= p[j]) {
                        //w[i] = max(w[i],w[i - p[j]] + v[j]);
                        int r = w[i - p[j]] + v[j];
                        if(w[i] < r) {
                            w[i] = r;
                            mark[i][j] = 1;
                        }
                    } else {
                        //w[i] = max(w[i],0 + v[j]);
                        if(w[i] < 0 + v[j]) {
                            w[i] = 0 + v[j];
                            mark[i][j] = 1;
                        }
                    }
                }
            }
        // for(int i = 0;i<=b;i++) {
        //     cout<<w[i]<<" ";
        // }
        // cout<<"\n";
        }
        vector<int>f;
        int nowv = b;
        int left = a;
        while(1) {
            // for(int i = a - 1;i>=0;i--) {
                if(mark[nowv][left]) {
                    nowv = nowv - p[left];
                    f.push_back(left);
                }
            // }
            left--;
            if(nowv == 0 || left == -1) break;
        }
        cout<<f.size();
        cout<<"\n";
        while(!f.empty()) {
            cout<<f.back()<<" ";f.pop_back();
        }
        cout<<"\n";
    }
    return 0;
}