// Author : ysh
// 2023/07/08 Sat 00:22:13
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

pair<vector<int>,vector<int>> input(int x) {
    vector<int>f(10),pre(x);
    for(int i = 0;i<x;i++) {
        int tmp;cin>>tmp;
        pre.at(i) = tmp;
        f.at(tmp)++;
    }
    return make_pair(f,pre);
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;cin>>n;
    while(n--) {
        bool o = 0;
        int n;cin>>n;
        auto tmp = input(n);
        cout<<"- 0"<<endl<<flush;
        pair<vector<int>,vector<int>> ttmp;
        int bin = 0;

        int ans = 0;
        for(int i = 0;i<=2;i++) {
            ttmp = input(n - bin);
            debug(ttmp.first,ttmp.second);
            if(tmp != ttmp) {
                for(int i = 0;i<10;i++) {
                    if(ttmp.first.at(i) > tmp.first.at(i)) {
                        if(tmp.first.at(i) == 0) for(int j = 0;j<n - bin;j++) {
                            if(ttmp.second.at(j) == i) {
                                cout<<"! "<<j + 1<<endl<<flush;
                                o = 1;
                                break;
                            }
                        }
                        if(o) break;
                        ans = i;
                    }
                }
                if(o) break;
                vector<int>tmp;
                for(int i = 0;i<n - bin;i++) {
                    if(ttmp.second.at(i) != ans) tmp.push_back(i + 1);
                }
                bin += tmp.size();
                cout<<"- "<<tmp.size();
                for(int i : tmp) cout<<" "<<i;
                cout<<endl<<flush;
            }
            swap(tmp,ttmp);
        }
        if(o) continue;
        ttmp = input(n - bin);
        if(bin + 1 == n) cout<<"! 0"<<endl<<flush;
        else for(int i = 0;i<10;i++) {
            if(ttmp.first.at(i) > tmp.first.at(i)) cout<<"! "<<i + 1<<endl<<flush;
        }
    }
    return 0;
}