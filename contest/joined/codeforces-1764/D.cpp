// Author : ysh
// 11/26/2022 Sat 23:36:01.78
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

    int a;cin>>a;
    vector<bool>mark(a,true);
    function<bool(int)> check = [&] (int x) {
        int last = 0;
        for(int i = 0;i<a;i++) {
            if(mark.at(i)) {
                last = i;
                break;
            }
        }
        int l = last;
        for(int i = 0;i<(a << 1);i++) {
            int p = (last + i) % a;
            if(!mark.at(i)) {
                
            }
        }
    };
    // mark = vector<bool>({true,true,false,false,true});
    // check(1);
    // return 2;
    vector<int>mk;
    // set<vector<int>>s;
    function<int()> ck = [&] () {
        if(!check(1)) {
            // debug(mark);
            // s.insert(mk);
            debug(mk);
            // cerr<<"1\n";
            return 1;
        }
        int ans = 0;
        for(int i = 0;i<a;i++) {
            if(mark.at(i)) {
                mark.at(i) = 0;
                mk.push_back(i + 1);
                ans += ck();
                mark.at(i) = 1;
                mk.pop_back();
            }                               
        }
        return ans;
    };
    cout<<ck();
    return 0;
}