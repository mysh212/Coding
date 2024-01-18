// Author : ysh
// 2024/01/12 Fri 16:45:53
#include<bits/stdc++.h>
using namespace std;
#define debug(i) (i) // {cerr<<"["<<#i<<"] : [";for(auto j : i) cerr<<j<<" ";cerr<<"]\n";}
inline bool gate(int a,int b,int c) {
    if(b == -1) return (a == 4 ? !c : c);
    if(a == 1) return (b && c);
    if(a == 2) return (b || c);
    if(a == 3) return (b ^ c);
    if(a == 4) return b ^ (!c);
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b,c,d;cin>>a>>b>>c>>d;
    vector<vector<int>>f(a + b + c);
    vector<int>g(a),v(b),in(a + b + c);
    
    for(int &i : g) cin>>i;
    for(int &j : v) cin>>j;
    for(int i = 0;i<d;i++) {
        int a,b;cin>>a>>b;
        a--;b--;
        f.at(a).push_back(b);
        in.at(b)++;
    }
    
    vector<bool>mark(a + b + c);
    for(int i = 0;i<a;i++) {
        mark.at(i) = (g.at(i) == 1);
    }
    
    #define isgate(i) (i >= a && i < a + b)
    
    vector<int>pre;
    {
        queue<int>q;
        for(int i = 0,len = a + b + c;i<len;i++) if(in.at(i) == 0) q.emplace(i);
        while(!q.empty()) {
            int now = q.front();q.pop();
            pre.push_back(now);
            for(int &i : f.at(now)) {
                if(--in.at(i) == 0) {
                    q.emplace(i);
                }
            }
        }
    }
    debug(pre);
    
    vector<bool>mk(a + b + c);
    vector<int>deep(a + b + c);
    for(int &i : pre) {
        for(int &j : f.at(i)) {
            deep.at(j) = max(deep.at(j),deep.at(i) + 1);
            if(isgate(j)) mark.at(j) = gate(v.at(j - a),(mk.at(j) ? mark.at(j) : -1),mark.at(i)),mk.at(j) = 1;
            else mark.at(j) = mark.at(i);
        }
    }
    debug(mark);
    
    cout<<*max_element(deep.begin() + (a + b),deep.end()) - 1<<"\n";
    for(int i = (a + b),len = (a + b + c);i<len;i++) {
        cout<<(mark.at(i) ? 1 : 0)<<" ";
    }
    return 0;
}