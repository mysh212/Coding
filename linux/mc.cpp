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
    bool c = 0;
    // char y[10000];
    string s;
    s.assign(args[1]);
    if(s.find('/') != -1) {
        for(int i = s.size() - 1;i >= 0;i--) {
            if(s.at(i) == '/') {
                s = s.substr(i + 1);
                break;
            }
        }
    }
    while(s.find(".cpp") != -1) s.replace(s.find(".cpp"),4,"");
    s = s + ".cpp";


    if(argc == 3 && (args[2][0] == 'z' || args[2][0] == 'Z')) {
        s = "Zerojudge-" + s;
        c = 1;
    }

    if(exists_test3(s)) {
        if(argc == 3 && args[2][0] == 'S') {
            c = 1;
        }
        if(!c) cerr<<"File already existed.\n";
        if(!c) return 1;
    }

    time_t now = time(0);
    tm *ltm = localtime(&now);
    string a = ctime(&now);
    string nt = tos(ltm->tm_mon + 1) + '/' + tos(ltm->tm_mday) + '/' + str(1900 + ltm->tm_year) + ' ' + a.substr(0,3) + ' ' + tosp(ltm->tm_hour)  +  ":" + tos(ltm->tm_min)  +  ":" + tos(ltm->tm_sec);
    string author = "// Author : ysh\n";
    string title = "#include<bits/stdc++.h>\nusing namespace std;\nint main() {\n    ios::sync_with_stdio(false);\n    cin.tie(0);\n\n    \n}";
    auto cpp = fopen(s.c_str(),"w");
    auto mc = fopen("mc.info","a");
    auto nwt = fopen("now.tmp","w");
    if((!c) && argc == 3) {
        string a;
        a.assign(args[2]);
        fprintf(cpp,"%s\n",(author + "// " + nt + "\n" + "// " + a + "\n" + title).c_str());
    } else {
        fprintf(cpp,"%s\n",(author + "// " + nt + "\n" + title).c_str());
    }
    fprintf(mc,"%s        %s\n",(nt + ".14").c_str(),s.c_str());
    fprintf(nwt,"%s\n",s.c_str());
    system(("code " + s).c_str());
    return 0;
}
