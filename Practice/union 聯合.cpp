#include<bits/stdc++.h>
using namespace std;
union pc {
    int i;
    char c;
};
int main() {
    pc acer={1024};
    pc *t=&acer;
    cout<<"before setting c, i="<<t->i<<"\n";
    t->c='A';
    cout<<"c="<<t->c<<"\n";
    cout<<"after setting c, i="<<t->i<<"\n";//124
    system("pause");
    return 0;
}
