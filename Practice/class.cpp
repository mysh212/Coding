// Author : ysh
// 06/15/2022 Wed  8:17:01.38
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    class box{
        public:
        int a = 0;
        int b = 0;
        void check() {
            cout<<a<<" "<<b<<"\n";
            // check();
        }
        bool operator<(box c) {
            return a < c.a;
        }
        explicit box() {
            a = 0;
            b = 0;
        }
        explicit box(int d,int e) {
            a = d;
            b = e;
        }
        // box(int f,int g):
        //     a(f), b(g) {};
    };
    box a = box(1,2);
    a.check();
    box b = box(3,4);
    b.check();
    cout<<(int) (a < b);
    return 0;
}