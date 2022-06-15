// Author : ysh
// 06/15/2022 Wed  9:17:37.78
#include<bits/stdc++.h>
using namespace std;
struct box{
    int a;
    int b;
    box(int a = 0,int b = 0):
        a(a), b(b) {};
    bool operator()(box a,box b) {
        return a.a < b.b;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<box,vector<box>,box>q;
    q.push(box(1,2));
    q.push(box(5,6));
    q.push(box(3,4));
    while(!q.empty()) {
        cout<<q.top().a<<" "<<q.top().b<<"\n";q.pop();
    }
    cout<<(int) ((box() (box(1,2),box(3,4))));
    return 0;
}