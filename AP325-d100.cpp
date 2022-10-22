// Author : ysh
// 10/05/2022 Wed 11:41:47.19
// https://judge.tcirc.tw/ShowProblem?problemid=d100
#include<bits/stdc++.h>
using namespace std;
vector<int>color;
vector<int>fc;
int ff(int);
bool mg(int,int);
inline int pr(int);
inline int pr(int x) {
    if(x & 1) return x - 1;
    return x + 1;
}
bool mg(int a,int b) {
    // if(ff(a) == ff(pr(b))) return 0;
    fc.at(ff(a)) = fc.at(ff(b));
    return 1;
}
int ff(int x) {
    if(fc.at(x) == x) return x;
    return fc.at(x) = ff(fc.at(x));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;cin>>t;
    while(t--) {
        int a,b;cin>>a>>b;
        color = vector<int>(a);
        fc = vector<int>(a);
        iota(fc.begin(),fc.end(),0);
        vector<vector<int>>f(a);
        for(int i = 0;i<b;i++) {
            int a,b;cin>>a>>b;
            f.at(a).push_back(b);
            f.at(b).push_back(a);
        }
        vector<bool>mark(a);
        bool bk = 0;
        function<void(int,int)> check = [&] (int last,int x) {
            if(last != -1 && ff(last) == ff(x)) bk = 1;
            if(bk) return;
            if(mark.at(x)) return;
            mark.at(x) = 1;
            for(int i : f.at(x)) {
                if(last != -1) {
                    mg(last,i);
                }
                // if(bk) cerr<<last<<" "<<x;
                check(x,i);
            }
        };
        for(int i = 0;i<a;i++) {
            if(!mark.at(i)) check(-1,i);
        }
        cout<<(bk ? "no\n" : "yes\n");
    }
    return 0;
}