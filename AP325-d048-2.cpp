// Author : ysh
// 09/09/2022 Fri  8:24:16.92
// https://judge.tcirc.tw/ShowProblem?problemid=d048
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    deque<int>f(n);
    int last = 0;
    for(int &i : f) {
        cin>>i;
        i = last += i;
    }
    f.push_front(0);
    function<int(int,int)> check = [&] (int l,int r) {
        if(l + 1 == r) return f.at(r) - f.at(l);
        int mmin = INT_MAX;
        for(int i = l + 1;i<r;i++) {
            mmin = min(mmin,check(l,i) + check(i,r));
        }
        return mmin + (f.at(r) - f.at(l));
    };
    cout<<last<<"\n"<<check(0,n) - (f.at(n) - f.at(0));
    return 0;
}