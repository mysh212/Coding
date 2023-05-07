// Author : ysh
// 05/07/2023 Sun  0:36:07.52
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>mark;
vector<int>f;
int a,b;
const int R = (int) 1e9 + 7;
int check(int x,int mask) {
    if(x == a) return (__builtin_popcount(mask) == b ? 1 : 0);
    if(mark.at(x).at(mask) != -1) return mark.at(x).at(mask);
    int sig = check(x + 1,mask);
    int tmp = mask & f.at(x);
    sig = sig + check(x + 1,tmp);
    sig = sig % R;
    return mark.at(x).at(mask) = sig;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        cin>>a>>b;
        mark = vector<vector<int>>(a,vector<int>(64,-1));
        f.clear();
        f.resize(a);
        for(int &i : f) {
            cin>>i;
        }
        cout<<check(0,63) - (b == 6 ? 1 : 0)<<"\n";
    }
    return 0;
}