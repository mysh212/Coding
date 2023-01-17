// Author : ysh
// 01/17/2023 Tue 21:23:38.16
#include<bits/stdc++.h>
using namespace std;
#define endno {return "-1";}
#define add(j) for(char i : j) s.push_back(i);
string solve(int a,int b) {
    if(a == 0 || b == 0 || (b & 1 && b < 11) || (a == 1 && b == 4)) endno;
    string s;
    if(b & 1) {
        if(a < 10) endno;
        if(b == 11) {
            if(a < 11) endno;
            if(a == 11) {
                for(int i = 1;i<=b - 11;i++)  add("2");
                for(int i = 1;i<=11;i++)  add("02");
                 add(" ");
                for(int i = 1;i<=11;i++)  add("20");
                for(int i = 1;i<=b - 11;i++)  add("2");
                return s;
            } else {
                // vector<int>tmp;
                for(int i = 0;i<b - 11;i++)  add("2");
                for(int i = 1;i<=10;i++)  add("20");
                 add("002");
                for(int i = 1;i <= a - 12;i++)  add("0");
                 add(" ");
                for(int i = 1;i <= a - 11;i++)  add("0");
                for(int i = 1;i<=11;i++)  add("20");
                for(int i = 1;i<=b - 11;i++)  add("2");
                //  add(" ");
                return s;
            }
        } else {
            if(a == 10) {
                for(int i = 0;i<b - 12;i++)  add("2");
                 add("0222");
                for(int i = 1;i<=9;i++)  add("02");
                 add(" ");
                for(int i = 1;i <= a - 10;i++)  add("0");
                for(int i = 1;i<=9;i++)  add("20");
                 add("2220");
                for(int i = 1;i<=b - 12;i++)  add("2");
                //  add(" ");
                return s;
            }
            for(int i = 0;i<b - 11;i++)  add("2");
            for(int i = 1;i<=10;i++)  add("20");
             add("002");
            for(int i = 1;i <= a - 12;i++)  add("0");
             add(" ");
            for(int i = 1;i <= a - 10;i++)  add("0");
            for(int i = 1;i<=9;i++)  add("20");
             add("2220");
            for(int i = 1;i<=b - 12;i++)  add("2");
            //  add(" ");
            return s;
        }
    }
    if(a == 1) {
        for(int i = 0;i<b - 2;i++) {
             add("2");
        }
         add("022 220");
        for(int i = 0;i<b - 2;i++) {
             add("2");
        }
        //  add(" ");
    } else {
        for(int i = 0;i < b - 1;i++) {
             add("2");
        }
         add("002");
        for(int i = 0;i<a - 2;i++) {
             add("0");
        }
         add(" ");
        for(int i = 0;i<a - 1;i++) {
             add("0");
        }
         add("220");
        for(int i = 0;i < b - 2;i++) {
             add("2");
        }
        //  add(" ");
    }
    return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    cout<<solve(a,b);
    return 0;
}