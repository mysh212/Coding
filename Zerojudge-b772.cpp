// Author : ysh
// 01/02/2022 Sun 22:53:45.16
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;    
    while(getline(cin,a)) {
        bool bk = false;
        string b;
        while(getline(cin,b)) {
            //cout<<a;
            stringstream ss;
            ss<<b;
            ss>>b;
            if(b=="end") break;
            if(b=="addhead") {
                string tmp;
                ss>>tmp;
                a = tmp + a;
                continue;
            }
            if(b=="addtail") {
                string tmp;
                ss>>tmp;
                a = a + tmp;
                continue;
            }
            if(b=="remove") {
                string tmp;
                ss>>tmp;
                while(a.find(tmp) != -1) {
                    a.replace(a.find(tmp),1,"");
                }
                continue;
            }
            if(b=="replace") {
                string tmp,ttmp;
                ss>>tmp>>ttmp;
                while(a.find(tmp) != -1) {
                    a.replace(a.find(tmp),1,ttmp);
                }
                continue;
            }
            cout<<"invalid command "<<b;
            bk = true;
        }
        cout<<(bk == false ? a : "")<<"\n";
    }
    return 0;
}