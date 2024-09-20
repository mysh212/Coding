// Author : ysh
// 2024/09/18 Wed 21:58:47
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    char a;
    while((a = getchar()) != EOF) {
        if(not(isalpha(a))) {
            cout<<a;
            continue;
        }
        if(not(isalpha(a - 2))) a = a + ('Z' - 'A' + 1);
        cout<<char(a - 2);
    }
    return 0;
}