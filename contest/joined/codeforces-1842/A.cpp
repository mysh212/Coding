// Author : ysh
// 2023/06/24 Sat 22:04:21
#include<bits/stdc++.h>
using namespace std;
#define one cout<<"Tsondu\n"
#define two cout<<"Tenzing\n"
#define all cout<<"Draw\n"
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        vector<int>f(a),g(b);
        for(int &i : f) cin>>i;
        for(int &i : g) cin>>i;

        multiset<int>left(f.begin(),f.end()),right(g.begin(),g.end());
        while(!(left.empty() || right.empty())) {
            for(int i = 0;i<=1;i++) {
                int aa = *prev(left.end());
                int bb = *right.begin();
                left.erase(prev(left.end()));
                right.erase(right.begin());
                int tmpa = aa - bb;
                int tmpb = -tmpa;
                aa = tmpa;
                bb = tmpb;
                if(aa > 0) left.insert(tmpa);
                if(bb > 0) right.insert(tmpb);
                if((left.empty() || right.empty()) && i == 0) break;
                swap(left,right);
            }
        }
        if(left.empty() && right.empty()) all;
        else if(left.empty()) two;
        else one;
    }
    return 0;
}