// Author : ysh
// 07/21/2022 Thu 19:55:59.74
// https://judge.tcirc.tw/ShowProblem?problemid=d046
#include<bits/stdc++.h>
using namespace std;
struct box{
    int x,y;
    bool operator<(box a) {
        return x * a.y < a.x * y;
    }
    explicit box(int x = 0,int y = 0):
        x(x), y(y) {};
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<box>f(n);
    for(box &i : f) {
        cin>>i.x;
    }
    for(box &i : f) {
        cin>>i.y;
    }
    sort(f.begin(),f.end());
    long long ans = 0;
    long long last = 0;
    for(box i : f) {
        ans += (last += i.x) * i.y;
    }
    cout<<ans;
    return 0;
}