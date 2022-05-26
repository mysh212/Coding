// Author : ysh
// 04/18/2022 Mon 21:57:23.02
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand(time(NULL));
    cout<<100<<"\n";
    for(int i = 0;i<100;i++) {
        cout<<rand() % 100<<" \n"[i == 99];
    }
    for(int i = 0;i<100;i++) {
        cout<<rand() % 100<<" \n"[i == 99];
    }
}