// Author : ysh
// 2023/07/28 Fri 15:14:00
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int mat[20][20] = { };
    int n, m ,k;
    cin >> n >> m >> k;
    vector<int> cost(k), la(n);
    for(int i = 0; i < n; ++i){
        cin >> la[i];
        --la[i];
    }

    vector<pii> edge(m);

    for(int i = 0; i <m; ++i){
        int x, y;
        cin >> x >>y;
        --x, --y;
        edge[i] = make_pair(x, y);
    }

    for(int i = 0; i <k; ++i){
        cin >> cost[i];
    }

    for(int i = 0; i < m; ++i){
        mat[la[edge[i].first]][la[edge[i].second]] = 1;
        mat[la[edge[i].second]][la[edge[i].first]] = 1;
    }

    int ans = -1;

    for(int s = 1; s < (1 << k); ++s){
        int now = 1;
        vector<int> v;
        for(int i = 0; i < k; ++i){
            if((1 << i) & s){
                v.push_back(i);
            }
        }
        bool flag = true;
        // for(int i = 0; i <v.size() - 1; ++i){
        //     if(mat[v[i]][v[i + 1]]){
        //         flag = false;
        //         break;
        //     }
        // }
        for(int i = 0; i <v.size(); ++i){
            for(int j = i + 1; j <v.size(); ++j){
                if(mat[v[i]][v[j]]){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            int cut = 0;
            for(int i = 0; i <v.size(); ++i){
                cut += cost[v[i]];
            }
            ans = max(ans, cut);
        }
    }

    cout << ans;

}