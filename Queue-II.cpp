// Author : ysh
// 2023/09/30 Sat 08:59:06
// https://codeforces.com/problemset/problem/490/B
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

#define left __left
#define right __right
vector<int>left,right;
int ff(vector<int>&f,int x) {
    if(f.at(x) == -1 || f.at(x) == x) return x;
    return ff(f,f.at(x));
}
void mg(vector<int>&f,int a,int b) {
    f.at(a) = b;
    return;
}
int fo(vector<int>&f,int x) {
    return (f.at(x) == -1 ? x : f.at(x));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    int m = n;
    left = right = vector<int>(int(1e6 + 1),-1);
    set<int>s;
    int root;
    while(n--) {
        int a,b;cin>>a>>b;
        if(a == 0) root = b,s.insert(b);
        if(b == 0) s.insert(a);
        if(a == 0 || b == 0) continue;
        mg(left,b,a);
        mg(right,a,b);
        s.insert(a);
        s.insert(b);
    }

    int l,r;l = 0;r = root;
    for(int i : s) {
        debug(i,ff(left,i));
        if(ff(left,i) != root) {
            l = ff(left,i);
            break;
        }
    }
    debug(root);
    do{
        if(m--) cout<<l<<" ";
        if(m-- > 0) cout<<r<<" ";
        r = fo(right,r);
        l = fo(right,l);
    } while(l != 0 && r != 0 && m > 0);
    return 0;
}