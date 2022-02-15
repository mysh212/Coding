// Author : ysh
// 02/13/2022 Sun 14:10:10.20
// https://codeforces.com/group/H0qY3QmnOW/contest/366708/problem/B
// WA
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    cin>>a>>b;
    cout<<(a % 2 ? "Odd" : "Even")<<"\n";
    cout<<(b % 2 ? "Odd" : "Even")<<"\n";
    //cout<<a<<" "<<b<<"\n";
    if(a % 2 == 1&&b % 2 == 0) {
        cout<<"Gunjyo";
        return 0;
    } else if(a % 2 == 0&&b % 2 == 1) {
        cout<<"Koying";
        return 0;
    } else {
        cout<<(a < b ? "Koying" : "Gunjyo");
    }
    return 0;
}