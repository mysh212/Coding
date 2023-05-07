// Author : ysh
// 05/06/2023 Sat 23:21:35.80
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        vector<vector<int>>f(a);
        vector<int>in(a);
        for(int i = 0;i<b;i++) {
            int a,b;cin>>a>>b;
            a--;b--;
            f.at(a).push_back(b);
            f.at(b).push_back(a);
            in.at(a)++;
            in.at(b)++;
        }
        map<int,int>m;
        for(int &i : in) {
            m[i]++;
        }

        if(m.size() == 2) {
            for(auto &i : m) {
                if(i.first == 1) continue;
                cout<<i.first<<" "<<i.first - 1<<"\n";
            }
            continue;
        }

        for(auto &i : m) {
            if(i.first == 1) continue;
            if(i.second == 1) cout<<i.first<<" ";
        }
        for(auto &i : m) {
            if(i.first == 1) continue;
            if(i.second != 1) cout<<i.first - 1<<"\n";
        }
    }
    return 0;
}