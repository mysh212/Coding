// Author : ysh
// 2024/01/21 Sun 22:10:08
// https://atcoder.jp/contests/abc192/tasks/abc192_d
// NF
#include<bits/stdc++.h>
using namespace std;
string a;
long long b;
inline bool check(int x) {

}
int ck(int l,int r) {
    if(l + 1 == r) return l;
    int mid = (l + r) >> 1;
    if(check(mid)) return ck(mid,r);
    return ck(l,mid);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>a>>b;


}