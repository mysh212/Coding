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

    // readnow();
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
    if(ac == 2) {
        string s1;
        s1.assign(as[1]);
        auto ff = fopen("tags.info","a");
        fprintf(ff,"%s\n" ,(s + "\	" + s1).c_str());
        fclose(ff);
        print("taged: " + s + "\t" + s1);
    }
    if(ac == 3) {
        string s1;
        s1.assign(as[1]);
        string s2;
        s2.assign(as[2]);
        s2 = findtroad(s2);
        auto ff = fopen("tags.info","a");
        fprintf(ff,"%s\n" ,(s2 + "\	" + s1).c_str());
        fclose(ff);
        print("taged: " + s2 + "\t" + s1);
    }
    return 0;
}