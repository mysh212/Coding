#include<bits/stdc++.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fstream>
void writenow(string);
inline bool exists_test3 (const std::string& name) {
  struct stat buffer;   
  return (stat (name.c_str(), &buffer) == 0); 
}
string findtroad(string s) {
    if(s.find('/') != -1) {
        for(int i = s.size() - 1;i >= 0;i--) {
            if(s.at(i) == '/') {
                s = s.substr(i + 1);
                break;
            }
        }
    }
    return s;
}
string readnow() {
    if(!exists_test3("now.tmp")) {
        print("road=");
        writenow(findtroad(input()));
    }
    auto f = fopen("now.tmp","r");
    string s;
    char c[10000];
    fscanf(f,"%s\n",&c);
    s.assign(c);
    return findtroad(s);
}
void writenow(string s) {
    auto f = fopen("now.tmp","w");
    fprintf(f,"%s\n",s);
    return;
}