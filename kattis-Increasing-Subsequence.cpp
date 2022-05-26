// Author : ysh
// 04/19/2022 Tue 12:22:34.90
// https://open.kattis.com/problems/increasingsubsequence
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAX=(int) 1e8 + 5;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<int>f;
    int tmp;
    for(int i =0;i<n;i++) {
        cin>>tmp;
        f.push_back(tmp);
    }
    vector<int>a(MAX);
    queue<int>q;
    for(int i = 0;i<n;i++) {
        if(a[f[i]] < a[f[i] - 1] + 1) {
            // a[f[i] - 1].assign(a[f[i]].begin(),a[f[i]].end());
            // a[f[i]].push_back(f[i]);
            a[f[i]] = a[f[i] - 1] + 1;
        } else continue;
        for(int j = f[i];j<MAX;j++) {
            if(j == MAX - 1) {
                if(a[j] < a[j - 1]) {
                    q.push(i);
                }
            }
            if(a[j - 1] > a[j]) {
                a[j] = a[j - 1];
                // a[j].assign(a[j - 1].begin(),a[j - 1].end());
            }
        }
    }
    cout<<a[MAX - 1]<<" ";
    while(!q.empty()) {
        cout<<f[q.front()]<<" ";q.pop();
    }
    cout<<"\n";
    return 0;
}