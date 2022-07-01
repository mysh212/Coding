// Author : ysh
// 06/26/2022 Sun 21:52:12.71
#include<bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = time(NULL);
    if(n % 5 == 0) cout<<"Hello, World!";
    if(n % 5 == 1) cout<<"hello, world";
    if(n % 5 == 2) cout<<"Halo, word!!!";
    if(n % 5 == 3) cout<<"世界，您好!"
    if(n % 5 == 4) cout<<"https://zerojudge.tw/ShowProblem?problemid=a001";
    std::this_thread::sleep_for(std::chrono::microseconds(1000000));
    return 0;
}
