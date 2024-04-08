// Author : ysh
// 2024/04/07 Sun 12:07:44
#include<bits/stdc++.h>
using namespace std;
class box{
    protected:
    int n;

    public:
    box(int n = 0):
        n(n) {};

    void add() {
        n++;
    }

    int get() {
        return n;
    }
};

class line : public box {
    private:
    int p;

    public:
    line(int p = 0):
        p(p) {};
    int sum() {
        return n + p;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    line p(1);
    cout<<p.sum()<<"\n";
    for(int i = 0;i<10;i++) {
        p.add();
        cout<<p.sum()<<"\n";
    }
}