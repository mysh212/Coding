// Author : ysh
// 09/06/2022 Tue 19:12:20.02
#include<bits/stdc++.h>
#include<tree>
using namespace std;
// #include<strint.h>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while(cin>>n) {
        tree<int> t = tree<int>(n + 1);
        for(int i = 0;i<n;i++) {
            int tmp;cin>>tmp;
            tmp = tmp - 1;
            t.add(tmp,1);
            cout<<t.sum(tmp + 1,n) + 1<<"\n";
        }
    }
    return 0;
}