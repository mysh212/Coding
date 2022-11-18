// Author : ysh
// 11/18/2022 Fri 14:24:14.20
// https://apcsclass.csie.ntnu.edu.tw/ShowProblem?problemid=a117
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...)
#endif

int n;
char a[] = {'A','B','C'};
int c = 0;
void check(int x,int a,int b,int tmp) {
    if(x == 0) return;
    check(x - 1,a,tmp,b);
    cout<<"ring "<<x<<" : "<<::a[a]<<" => "<<::a[b]<<"\n";
    c++;
    check(x - 1,tmp,b,a);
}
void ck(int x,int now) {
    if(x == 0) return;
    int tmp;
    int to;
    if(x % 3 == 2) to = 1;
    if(x % 3 == 1) to = 0;
    if(x % 3 == 0) to = 2;
    if(now == to) {
        ck(x - 1,now);
        return;
    }
    tmp = 0 ^ 1 ^ 2 ^ to ^ now;
    check(x - 1,now,tmp,to);
    // debug(now,tmp,to);
    cout<<"ring "<<x<<" : "<<::a[now]<<" => "<<::a[to]<<"\n";
    c++;
    ck(x - 1,tmp);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>n;
    // vector<int>f;
    ck(n,0);
    cout<<"共需"<<c<<"個移動";
    return 0;
}