// Author : ysh
// 02/06/2022 Sun 17:55:12.38
// http://e.co/problem/00073
// WA
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int i = 1;
    int lost = 0;
    int twice = 0;
    bool lf,tf;lf=tf=0;
    while(cin>>n) {
        if(lf == 0&&tf == 0) {
            if(n > i) {
                lost = i;
                lf=1;
            } else if(n < i) {
                twice = n;
                tf=1;
            }
        }
        if(lf == 1&&n == i) {
            twice = i;
            break;
        }
        if(tf == 1&&n == i) {
            lost = i - 1;
            break;
        }
        i++;
    }
    if(lost == 0) lost = i - 1;
    cout<<twice<<" "<<lost;
    return 0;
}