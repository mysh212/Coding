// Author : ysh
// 07/16/2022 Sat 15:20:10.85
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;
    while(getline(cin,a)) {
        vector<char>f;
        bool c = 0;
        for(char i : a) {
            if(i == '}' && f.back() == '{') {
                if(f.empty()) {
                    //cout<<"no\n";
                    c = 1;
                    break;
                }
                f.pop_back();
                continue;
            }
            if(i == ']' && f.back() == '[') {
                if(f.empty()) {
                    //cout<<"no\n";
                    c = 1;
                    break;
                }
                f.pop_back();
                continue;
            }
            if(i == ')' && f.back() == '(') {
                if(f.empty()) {
                    //cout<<"no\n";
                    c = 1;
                    break;
                }
                f.pop_back();
                continue;
            }
            if(i == '[') {
                f.push_back(i);
                continue;
            }
            if(i == '(') {
                f.push_back(i);
                continue;
            }
            if(i == '{') {
                f.push_back(i);
                continue;
            }
            //cout<<"no\n";
            c = 1;
            break;
        }
        if((!c) && (f.empty())) cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;
}