#include <iostream>
#include<sstream>
#include <ctime>
#include<string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
using namespace std;
#include</home/ysh/桌面/Coding/Coding/linux/strint.h>

inline string tos(int a) {
    if(a == 0) return "00";
    string s = str(a);
    if(s.size() == 1) s = '0' + s;
    return s;
}
inline string tosp(int a) {
    if(a == 0) return "00";
    string s = str(a);
    if(s.size() == 1) s = ' ' + s;
    return s;
}
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
    // char y[10000];
    string s;
    if(argc == 3 && (args[2][0] == 'z' || args[2][0] == 'Z')) {
        s.assign(args[1]);
        if(s.find(".cpp") != -1) s.replace(s.find(".cpp"),4,"");
        s = "Zerojudge-" + s;
        s = s + ".cpp";
        c = 0;
    } else {
        string s;
        s.assign(args[1]);
        if(s.find(".cpp") != -1) s.replace(s.find(".cpp"),4,"");
        s = s + ".cpp";
    }
    if(exists_test3(s.c_str())) {
        c = 0;
        if(!(argc == 3 && args[2][0] == 'S')) {
            cerr<<" File already existed.\n";
            return 1;
        }
    }
    freopen(s.c_str(),"w",stdout);
    cout<<"// Author : ysh\n// ";
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string a = ctime(&now);
    cout<<tos(ltm->tm_mon + 1)<<'/'<<tos(ltm->tm_mday)<<'/'<<1900 + ltm->tm_year<<' '<<a.substr(0,3)<<' '<<tosp(ltm->tm_hour) << ":"<<tos(ltm->tm_min) << ":"<<tos(ltm->tm_sec) << '\n';
    // char z[10000];
    string z;
    stringstream r;
    r<<tos(ltm->tm_mon + 1)<<'/'<<tos(ltm->tm_mday)<<'/'<<1900 + ltm->tm_year;
    r<<'-'<<a.substr(0,3);
    r<<'-'<<tosp(ltm->tm_hour) << ":"<<tos(ltm->tm_min) << ":"<<tos(ltm->tm_sec) << '\n';
    string t;
    while(r >> t) {
        while(t.find('-') != -1) t.replace(t.find('-'),1," ");
        z = z + t;
    }
    z = z + ".14";
    if(argc == 3 && c) {
        cout<<"// "<<args[2]<<"\n";
    }
    cout<<"#include<bits/stdc++.h>\nusing namespace std;\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(0);\n\n    \n}";
    // char x[10000];
    // strcat(x,"code ");
    // strcat(x,y);
    int tmp = system(("code " + s).c_str());
    auto f = fopen("mc.info","a");
    fprintf(f,"%s        %s\n",z,s.c_str());
    return 0;
}
