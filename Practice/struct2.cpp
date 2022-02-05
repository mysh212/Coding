// Author : ysh
// 01/27/2022 Thu 16:16:45.56
#include<bits/stdc++.h>
using namespace std;
struct test {
    int a;
    int c[6];
    inline int bigger(int a,int b) {
        return a>b;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    test a[2];
    a[0] = {0,{0,1,2,3,4,5}};
    a[1] = {0,{1,1,1,1,1,1}};
    a[1].c[3] = 3;
    cout<<a[0].a<<"  ";
    for(auto i : a[0].c) {
        cout<<i<<" ";
    }
    cout<<"\n"<<a[1].a<<"  ";
    for(auto i : a[1].c) {
        cout<<i<<" ";
    }
    cout<<"\n";
    cout<<a[0].bigger(1,3);
}