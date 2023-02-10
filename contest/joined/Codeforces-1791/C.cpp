// Author : ysh
// 02/03/2023 Fri 23:07:45.61
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        string a;cin>>a;
        deque<char>f(a.begin(),a.end());
        while(!(f.size() <= 1)) {
            if((f.front() == '1') ^ (f.back() == '1')) {
                f.pop_front();
                f.pop_back();
            } else {
                break;
            }
        }
        cout<<f.size();
        cout<<"\n";
    }
    return 0;
}