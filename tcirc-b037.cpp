// Author : ysh
// 03/14/2023 Tue 13:44:35.73
// https://judge.tcirc.tw/ShowProblem?problemid=b037
#include<bits/stdc++.h>
using namespace std;
#include<fast>
#define upper(i) (i >= 'A' && i <= 'Z' ? i : i + ('A' - 'a'))
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    char a;
    vector<int>f(26);
    while(a = getchar(),a != EOF) {
        if(isalpha(a)) f.at(upper(a) - 'A')++;
    }
    for(int i = 0;i<=25;i++) if(f.at(i) != 0) printf("'%c': %d\n",'a' + i,f.at(i));
}