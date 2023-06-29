// Author : ysh
// 2023/06/29 Thu 11:35:32
#include<bits/stdc++.h>
using namespace std;
#include<square>
struct fib{
    unsigned long long ___mod = 0;
    int operator() (unsigned long long x) {
        assert(x >= 0);
        if(x == 0) return 1;
        vector<vector<unsigned long long>>pre({{1,1},{1,0}});
        vector<vector<unsigned long long>>f({{0,0},{1,0}});
        t<unsigned long long>p(pre);
        t<unsigned long long>v(f);
        if(___mod != 0) {
            p.mod(___mod);
            v.mod(___mod);
        }
        return ((p ^ x) * v).f.at(0).at(0);
    }
    fib(unsigned long long x = 0):
        ___mod(x) {};
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for(int i = 0;i<100;i++) cout<<fib(10)(i);
}