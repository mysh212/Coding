// Author : ysh
// 2024/03/19 Tue 23:21:36
// https://codeforces.com/contest/27/problem/C
#include<bits/stdc++.h>
using namespace std;
#include<slow>
inline bool cp(pair<int,int>a,int b) {
    return a.first < b;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vc<int>f(n);
    cin>>f;
    re(2) {
        multiset<pair<int,int>>l,r;

        int t = 0;
        repo(&i,f) l.insert({i,t++});

        for(int i = n - 1;i>=0;i--) {
            auto found = l.lower_bound(make_pair(f.at(i),i));
            l.erase(found);

            auto foundl = l.lower_bound(make_pair(f.at(i) + 1,0));
            auto foundr = r.lower_bound(make_pair(f.at(i) + 1,0));

            if(foundl != l.end() && foundr != r.end()) {
                cout<<"3\n";
                cout<<foundl->second + 1<<" "<<i + 1<<" "<<foundr->second + 1<<"\n";
                return 0;
            }
            r.insert({f.at(i),i});
        }

        repo(&i,f) i = -i;
    }
    cout<<0;
    return 0;
}