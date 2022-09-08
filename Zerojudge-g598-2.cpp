// Author : ysh
// 09/07/2022 Wed 10:36:50.25
#include<bits/stdc++.h>
using namespace std;
vector<int>f;
int t = 0;
bool check(int,int);
vector<vector<int>>l;
int n,m;
inline int pr(int a) {
    int tmp = a >> 1;
    tmp = tmp << 1;
    if(tmp == a) {
        return a + 1;
    }
    return tmp;
}
bool mg(int a,int b) {
    l.at(a).push_back(b);
    l.at(b).push_back(a);
    if(f.at(a) == -1) {
        if(f.at(b) == -1) {
            f.at(a) = t++;
            f.at(b) = t++;
            return 1;
        }
        f.at(a) = pr(f.at(b));
        return 1;
    }
    if(f.at(b) == -1) {
        f.at(b) = pr(f.at(a));
        return 1;
    }
    return check(a,b);
}
bool check(int a,int b) {
    if(f.at(a) == f.at(b)) return 0;
    if(f.at(a) == pr(f.at(b))) return 1;
    if(f.at(a) != pr(f.at(b))) {
        // array<array<int,2>,2>mk = {{f[a],pr(f[a])},{pr(f[b]),f[b]}};
        vector<bool>mark(n);
        function<bool(int,int)> run = [&] (int x,int c) {
            if(mark.at(x)) {
                if(f.at(x) == c) return true;
                return false;
            }
            mark.at(x) = 1;
            f[x] = c;
            bool now = true;
            for(int i : l.at(x)) {
                now = now && run(i,pr(c));
            }
            return now;
        };
        return run(b,pr(f.at(a)));
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n>>m;
    l.resize(n,vector<int>());
    f.resize(n,-1);
    for(int i = 0;i<m;i++) {
        int a,b;cin>>a>>b;
        mg(a,b);
    }
    vector<int> bkp = f;
    vector<vector<int>> bl = l;
    int a,b;cin>>a>>b;
    bool c = 0;
    for(int i = 1;i<=a;i++) {
        c = 0;
        for(int j = 0;j<b;j++) {
            int a,b;cin>>a>>b;
            if(c) continue;
            if(!mg(a,b)) {
                // for(int i : f) cout<<i<<" ";
                // cout<<"\n";
                f = bkp;
                l = bl;
                // for(int i : f) cout<<i<<" ";
                // cout<<"\n\n";
                c = 1;
                cout<<i<<"\n";
            }
        }
    }
        // for(int i : f) cout<<i<<" ";
        // cout<<"\n";
    return 0;
}