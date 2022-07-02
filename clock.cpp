// Author : ysh
// 06/19/2022 Sun  8:06:59.77
#include<bits/stdc++.h>
using namespace std;
int main(int argc, char *args[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    clock_t t = clock();
    if(argc == 1) {
        cerr<<"[Error usage]\n";
        return -1;
    }
    char x[10000];
    strcat(x,"call ");
    strcat(x,args[1]);
    // cerr<<x;
    // system("pause");
    int tmp = system(x);
    cerr<<"\n[Progress Return "<<tmp<<"]\n";
    cerr<<"[Running period "<<(clock() - t) / 1000.0<<" sec]\n";
    return 0;
}