// Author : ysh
// 01/23/2022 Sun 16:40:33.57
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    queue<int>f;
    f.push(7);
    f.push(8);
    f.push(9);
    f.pop();
    f.pop();
    f.pop();
    cout<<f.empty();
    while(!f.empty()) f.pop();
    return 0;




    /*
    while(1) {
        int n;cin>>n;
        if(n == 0) {
            f.pop();
        } else if(n == -1) {
            while(!f.empty()) {
                cout<<f.front()<<" ";f.pop();
            }
            break;
        } else {
            f.push(n);
        }
    }
    return 0;
    */
}
// 1 2 3 4 5 6 7 8 9 8 9 7 6 5 4 3 3 2 3 0 0 0 -1