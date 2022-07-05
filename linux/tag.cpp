// Author : ysh
// 07/03/2022 Sun 16:06:43
#include<bits/stdc++.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
using namespace std;
#include</home/ysh/桌面/Coding/Coding/library/strint.h>
#include</home/ysh/桌面/Coding/Coding/library/linux.h>
int main(int ac,char *as[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s = "";
    if(ac == 1) {
        print("[Error Usage]");
        return 1;
    }
    if(!exists_test3("now.tmp")) {
        print("road=","");
        s = input();
    } else {
        s = readnow();
    }
    s = findtroad(s);
}