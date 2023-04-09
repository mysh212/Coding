// Author : ysh
// 04/09/2023 Sun 14:40:02.71
#include<bits/stdc++.h>
// #include<bits/extc++.h>
using namespace std;
// using namespace __gnu_pbds;
#define no cout<<"Not ghost key condition!\n";
#define yes(i) cout<<"Find ghosy key: "<<i<<"\n";
pair<int,int> L(pair<int,int>&a,pair<int,int>&b,pair<int,int>&c) {
    map<int,int>xx,yy;
    xx[a.first]++;
    xx[b.first]++;
    xx[c.first]++;
    yy[a.second]++;
    yy[b.second]++;
    yy[c.second]++;
    bool yesx = 0,yesy = 0;
    int xxx,yyy;
    for(auto i : xx) {if(i.second == 2) yesx = 1; else xxx = i.first;}
    for(auto i : yy) {if(i.second == 2) yesy = 1; else yyy = i.first;}
    if(!(yesx && yesy)) return {-1,-1};
    else return {xxx,yyy};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,n,m;cin>>a>>b>>n>>m;
    vector<vector<int>>f(a + 1,vector<int>(b + 1,-1));
    map<int,pair<int,int>>re;
    for(int i = 0;i<n;i++) {
        int a,b,c;cin>>a>>b>>c;
        f.at(b).at(c) = a;
        re.insert({a,{b,c}});
    }

    for(int i = 0;i<m;i++) {
        int a,b,c;cin>>a>>b>>c;
        if(a == b || b == c || c == a) {
            no;
            continue;
        }
        auto aa = re.find(a)->second;
        auto bb = re.find(b)->second;
        auto cc = re.find(c)->second;
        auto now = L(aa,bb,cc);
        if(now == make_pair(-1,-1)) {
            no;
            continue;
        }
        if(f.at(now.first).at(now.second) == -1) {
            no;
            continue;
        }
        yes(f.at(now.first).at(now.second));
    }
    return 0;
}