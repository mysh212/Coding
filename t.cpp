// Author : ysh
// 11/05/2022 Sat 15:21:52.78
#include<bits/stdc++.h>
using namespace std;
void cp(int l,int r) {
    if(l == r) {
        cout<<l<<endl;
        exit(0);
    }
    int mid = (l + r) >> 1;
    cout<<mid<<endl;
    string a;cin>>a;
    if(a == "lower") cp(l,mid);
    if(a == "higher") cp(mid + 1,r);
    if(a == "correct") exit(0);
    return;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    cp(1,1000);
    return 0;
}