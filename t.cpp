// Author : ysh
// 04/28/2023 Fri 23:25:36.78
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        b = b / __gcd(a,b);
        string now = "";
        int left = 1;
        set<string>s;
        int t = 0;
        while(++t) {
            left = left * 10;
            now = now + (char) ('0' + (left / b));
            left = left % b;
            if(s.find(now) != s.end()) {
                cout<<(t >> 1)<<"\n";
                break;
            }
            s.insert(now + now);
        }
    }
    return 0;
}