#include <iostream>
#include <ctime>
#include<string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
using namespace std;
inline bool exists_test3 (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}
int main(int argc,char *args[]) {
    if(argc == 1) {
        cerr<<"[Error Usage]\n";
        return 1;
    }
    bool c = 1;
    char y[10000];
    string s;
    s.assign(args[1]);
    if(s.find(".cpp") != -1) s.replace(s.find(".cpp"),4,"");
    strcat(y,s.c_str());
    strcat(y,".cpp");
    if(exists_test3(y)) {
        c = 0;
        if(!(argc == 3 && args[2][0] == 'S')) {
            cerr<<" File already existed.\n";
            return 1;
        }
    }
    freopen(y,"w",stdout);
    cout<<"// Author : ysh\n// ";
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string a = ctime(&now);
    cout<<ltm->tm_mon<<'/'<<ltm->tm_mday<<'/'<<1900 + ltm->tm_year<<' '<<a.substr(0,3)<<' '<<ltm->tm_hour << ":"<<ltm->tm_min << ":"<<ltm->tm_sec << '\n';
    if(argc == 3 && c) {
        cout<<"// "<<args[2]<<"\n";
    }
    cout<<"#include<bits/stdc++.h>\nusing namespace std;\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(0);\n\n    \n}";
    char x[10000];
    strcat(x,"code ");
    strcat(x,y);
    system(x);
}
