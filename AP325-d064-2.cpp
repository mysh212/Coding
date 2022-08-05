// Author : ysh
// 08/04/2022 Thu 15:26:22.66
#include<bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include<C:\Users\Public\debug.h>
#else
#define debug(...) '*'
#define printf(...) '*'
#endif

int ans = 0;
vector<int>f;
priority_queue<int> check(int l,int r) {
    // debug(l,r);
    // system("pause");
    priority_queue<int>q;
    if(l == r) {
        q.push(f[l]);
        return q;
    }
    int mid = (l + r) >> 1;
    auto fl = check(l,mid);
    auto fr = check(mid + 1,r);
    int c = 0;
    int now = INT_MAX;
    while(!fr.empty()) {
        if(fl.empty()) {
            if(c != -1) ans += c;
            q.push(fr.top());fr.pop();
            continue;
        }
        bool o = 0;
        while(now > fr.top()) {
            if(fl.empty()) {
                if(c != -1) ans += c;
                o = 1;
                break;
            }
            now = fl.top();fl.pop();
            q.push(now);
            c++;
        }
        if(o) continue;
        ans = ans + c;
        q.push(fr.top());fr.pop();
    }
    while(!fl.empty()) {
        q.push(fl.top());fl.pop();
    }
    return q;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    f.resize(n);
    for(int &i : f) {
        cin>>i;
    }
    auto q = check(0,n - 1);
    while(!q.empty()) { 
        cout<<q.top()<<" ";q.pop();
    }
    cout<<"\n";
    cout<<ans;
    return 0;
}