// Author : ysh
// 07/17/2022 Sun 11:46:56
#include<bits/stdc++.h>
using namespace std;
#include</home/ysh/桌面/Coding/Coding/library/strint.h>
#include</home/ysh/桌面/Coding/Coding/library/linux.h>
int main(int ac,char *as[]) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    if(ac == 1) {
        string now = findtroad(readnow());
        now = "xclip -selection c \"" + now + "\"";
        system(now.c_str());
        return 0;
    }
    if(ac == 2) {
        string s;
        s.assign(as[1]);
        writenow(findtroad(s));
        s = "xclip -selection c " + s;
        system(s.c_str());
        return 0;
    }
    cerr<<"[Error Usage]\n";
    return 1;
}
