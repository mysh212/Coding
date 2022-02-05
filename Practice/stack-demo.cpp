// Author : ysh
// 01/23/2022 Sun 16:40:33.57
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    stack<int>f;
    while(1) {
        int n;cin>>n;
        if(n == 0) {
            f.pop();
        } else if(n == -1) {
            while(!f.empty()) {
                cout<<f.top()<<" ";f.pop();
            }
            break;
        } else {
            f.push(n);
        }
    }
    return 0;
}