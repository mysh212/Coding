// Author : ysh
// 02/21/2023 Tue 14:20:26.29
// https://codeforces.com/gym/425267
#include<bits/stdc++.h>
using namespace std;
deque<int> check(string a) {
    int n = a.size();
    deque<int>f(n);
    int l = 0,r = 0;
    for(int i = 1;i<n;i++) {
        f[i] = max(0,min(r - i + 1,f[i - l]));
        while(i + f[i] < n && a[f[i]] == a[i + f[i]]) f[i]++;
        if(i + f[i] - 1 > r) l = i,r = i + f[i] - 1;
    }
    return f;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a,b;cin>>a>>b;
    deque<int>left(check(b + " " + a));
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    deque<int>right(check(b + " " + a));
    for(int i = 0,len = b.size();i <= len;i++) left.pop_front();
    for(int i = 0,len = b.size();i <= len;i++) right.pop_front();
    reverse(right.begin(),right.end());
    swap(left,right);
    // for(int i : left) cerr<<i<<" ";
    // cerr<<"\n";
    // for(int i : right) cerr<<i<<" ";
    // cerr<<"\n";

    vector<int>ans;
    for(int i = 0,len = a.size();i<len;i++) {
        if(i + b.size() <= len) if(right.at(i) + left.at(i + b.size() - 1) >= b.size() - 1) ans.push_back(i + 1);
    }
    cout<<ans.size()<<"\n";
    for(int &i : ans) cout<<i<<" ";
    return 0;
}