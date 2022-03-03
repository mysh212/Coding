// Author : ysh
// 02/22/2022 Tue 12:57:32.37
// WA
#include<bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n,ll;cin>>n>>ll;
    vector<int>f;
    map<int,int>g;
    bitset<200>e;
    e.reset();
    int a[n+2] = {};
    int ans,mmax;ans=mmax=0;
    int tmp;
    e.set(0);
    e.set(ll);
    g.insert({0,ll+1});
    g.insert({n+1,ll+1});
    for(int i = 1;i<=n;i++) {
        cin>>tmp;
        a[i] = tmp;
        e.set(tmp);
    }
    for(int i = 0;i<n;i++) {
        cin>>tmp;
        g.insert({a[i],tmp});
    }
    int i = e._Find_next(e._Find_first());
    f.push_back(i);
    while(1) {
        //cout<<e.to_string()<<"\n";
        for(int i : f) {
            cout<<i<<" ";
        }
        cout<<"\n";
        system("pause");
        int l = f.back();
        int r = e._Find_next(i);
        if(r == 200) break;
        int d = g.find(i)->second;
        printf("%d\n",i);
        if(i - d >= l||i + d <= r) {
            e[i] = 0;
            i = l;
            if(!f.empty()) f.pop_back();
            ans++;
            mmax = max(mmax,d);
            continue;
        }
        f.push_back(i);
        i = r;
    }
    cout<<ans<<"\n"<<mmax;
}