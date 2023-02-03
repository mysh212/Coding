// Author : ysh
// 01/24/2023 Tue 19:40:36.19
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=854&page=show_problem&problem=762
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    int r = 0;
    while(1) {
        r++;
        set<int>s;
        vector<vector<int>>f(100,vector<int>(100,1e9));
        bool c = 0;
        while(cin>>a>>b && (a || b)) {
            c = 1;
            a--;b--;
            f.at(a).at(b) = 1;
            s.insert(a);
            s.insert(b);
        }
        if(!c) break;
        for(int i = 0;i<100;i++) f.at(i).at(i) = 0;
        for(int i = 0;i<100;i++) {
            for(int j = 0;j<100;j++) {
                for(int k = 0;k<100;k++) {
                    if(j == k) continue;
                    f.at(j).at(k) = min(f.at(j).at(k),f.at(j).at(i) + f.at(i).at(k));
                }
            }
        }
        int sig = 0;
        for(int i = 0;i<100;i++) {
            for(int j = 0;j<100;j++) {
                if(f.at(i).at(j) != (int) 1e9) sig = sig + f.at(i).at(j);
            }
        }
        cout<<fixed<<setprecision(3)<<"Case "<<r<<": average length between pages = "<<sig * 1.0 / ((s.size() * (s.size() - 1)))<<" clicks\n";
    }
    return 0;
}