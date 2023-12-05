// Author : ysh
// 2023/11/29 Wed 23:52:45
// https://cses.fi/problemset/task/1750
#include<bits/stdc++.h>
using namespace std;
#include<fast>
#include<slow>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vc<int>f(a);
    repo(&k,f) cin>>k;

    repo(&i,f) i--;
    vc<vc<int>>mark(a,vc<int>(32));
    re(i,a) mark.at(i).at(0) = f.at(i);

    re(j,1,32) re(i,a) mark.at(i).at(j) = mark.at(mark.at(i).at(j - 1)).at(j - 1);

    while(b--) {
        int a,b;cin>>a>>b;
        a--;
        re(i,32) if(b & (1 << i)) a = mark.at(a).at(i);
        cout<<a + 1<<"\n";
    }
    return 0;
}