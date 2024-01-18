// Author : ysh
// 2024/01/13 Sat 15:26:11
// https://acm.hdu.edu.cn/showproblem.php?pid=3689
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#define out(i) cout<<fixed<<setprecision(2)<<(i * 100)<<"%\n"
vector<int> check(string x) {
    int n = x.size();
    vector<int>f(n);
    for(int i = 1;i<n;i++) {
        int p = f.at(i - 1);
        while(p != 0 && x.at(p) != x.at(i)) p = f.at(p - 1);
        if(x.at(p) == x.at(i)) f.at(i) = p + 1;
    }
    return f;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    while(cin>>a>>b,!(a == 0 && b == 0)) {
        map<char,double>m;
        for(int i = 0;i<a;i++) {
            char a;
            double b;
            cin>>a>>b;
            m.insert({a,b});
        }
        string r;cin>>r;
        int n = r.size();
        for(char &i : r) {
            if(m.find(i) == m.end()) {
                out(0.0);
                goto no;
            }
        }
        goto yes;

        no:
        continue;

        yes:

        auto pre = check(r);
        debug(pre);
        vector<vector<double>>f(n + 1,vector<double>(b + 1));
        f.at(0).at(0) = 1;
        for(int j = 0;j<b;j++) {
            for(int i = 0;i<n;i++) {
                for(auto &k : m) {
                    int p = i;
                    while(p != 0 && r.at(p) != k.first) p = pre.at(p - 1);
                    if(r.at(p) == k.first) p++;
                    // else p = 0;
                    debug(p,i,j,k.first);
                    f.at(p).at(j + 1) += f.at(i).at(j) * k.second;
                }
            }
        }
        double aans = accumulate(f.at(n).begin(),f.at(n).end(),0.0);
        out(aans);
    }
    return 0;
}


