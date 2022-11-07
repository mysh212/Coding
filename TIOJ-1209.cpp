// Author : ysh
// 10/27/2022 Thu  7:53:48.37
// https://tioj.ck.tp.edu.tw/problems/1209
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

    int a,b;
    while(cin>>a>>b) {
        if(a == b && b == 0) return 0;
        vector<vector<int>>f(a);
        while(b--) {
            int a,b;cin>>a>>b;
            a--;b--;
            f.at(a).push_back(b);
            f.at(b).push_back(a);
        }
        vector<bool>mark(a);
        vector<bool>color(a);
        function<bool(int,int)> check = [&] (bool last,int x) {
            if(mark.at(x)) return 1;
            mark.at(x) = 1;
            for(int &i : f.at(x)) {
                if(mark.at(i) && (color.at(i) != last)) {
                    return 0;
                }
                // if(mark.at(i)) return 1;
                // mark.at(i) = 1;
                color.at(i) = last;
                if(!check(!last,i)) return 0;
            }
            return 1;
        };
        bool c = 0;
        for(int i = 0;i<a;i++) {
            if(!mark.at(i)) if(!check(1,i)) {
                c = 1;
                cout<<"No\n";
                break;
            }
        }
        debug(mark);
        debug(color);
        if(!c) cout<<"Yes\n";
    }
    return 0;
}