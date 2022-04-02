// Author : ysh
// 03/28/2022 Mon 18:42:38.28
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    bitset<27>f;
    // f.reset();
    string a;
    while(cin>>a) {
        f.reset();
        for(char i : a) {
            char j = i;
            if(!((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))) continue;
            if(i >= 'A' && i <= 'Z') j = i - ('A' - 'a');
            f.flip(((int) j) - ((int) 'a'));
        }
        int c = f.count();
        bool t = c == 0 || c == 1;
        cout<<(t ? "yes !" : "no...")<<"\n";
    }
    return 0;
}