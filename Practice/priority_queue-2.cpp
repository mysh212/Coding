// Author : ysh
// 06/30/2022 Thu 21:41:48.93
#include<bits/stdc++.h>
using namespace std;
struct box{
    int a = 0;
    int b,c;
    bool d;
};
struct cp{
    bool operator() (int a,int b) {
        return a>b;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // sort(a.begin(),a.end(),cp);
    priority_queue<int,vector<int>,cp>f;
    f.push(1);
    f.push(2);
    f.push(3);
    f.push(2);
    f.push(1);
    while(!f.empty()) {
        cout<<f.top()<<" ";f.pop();
    }
    return 0;
}