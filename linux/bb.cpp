// Author : ysh
// 06/19/2022 Sun  8:06:59.77
#include<bits/stdc++.h>
using namespace std;
#include</home/ysh/桌面/Coding/Coding/linux/strint.h>
int main(int argc, char *args[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    clock_t t = clock();
    if(argc == 1) {
        auto f = fopen("now.tmp","r");
        char z[10000];
        fscanf(f,"%s",z);
        char x[10000];
        string a;
        a.assign(z);
        a.replace(a.find(".cpp"),4,"");
        strcat(x,"g++ ");
        strcat(x,z);
        strcat(x," -O2 -std=c++11 -DLOCAL -o ");
        strcat(x,a.c_str());
        strcat(x,".o ");
        char y[10000];
        strcat(y,"./");
        strcat(y,a.c_str());
        strcat(y,".o");
        // cerr<<x;
        // system("pause");
        cerr<<" >Start building...\n";
        int tmp = system(x);
        if(tmp == 0) {
            cerr<<" >Finished\n\n";
            tmp = system(y);
        }
        cerr<<"\n[Progress return "<<tmp<<"]\n";
        cerr<<"[Running period "<<(clock() - t) / 1000.0<<" sec]\n";
        return 0;
        // cerr<<"[Error usage]\n";
        // return -1;
    }
    auto f = fopen("now.tmp","w");
    fprintf(f,"%s",args[1]);
    char x[10000];
    string a;
    a.assign(args[1]);
    a.replace(a.find(".cpp"),4,"");
    strcat(x,"g++ ");
    strcat(x,args[1]);
    strcat(x," -O2 -std=c++11 -DLOCAL -o ");
    strcat(x,a.c_str());
    strcat(x,".o ");
    char y[10000];
    strcat(y,"./");
    strcat(y,a.c_str());
    strcat(y,".o");
    // cerr<<x;
    // system("pause");
    cerr<<" >Start building...\n";
    int tmp = system(x);
    if(tmp == 0) {
        cerr<<" >Finished\n\n";
        tmp = system(y);
    }
    cerr<<"\n[Progress return "<<tmp<<"]\n";
    cerr<<"[Running period "<<(clock() - t) / 1000.0<<" sec]\n";
    return 0;
}