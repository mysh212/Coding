// Author : ysh
// 04/07/2022 Thu  8:27:06.29
// https://open.kattis.com/problems/knapsack
// TLE
#include<bits/stdc++.h>
using namespace std;
#define p system("pause");
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;
    while(cin>>a>>b) {
        cerr<<1;
        pair<int,int> c[b+1][a+1] = {};
        pair<int,int> d[b+1] = {};
        {
        int tmpa,tmpb;
        for(int i = 1;i<=b;i++) {
            cin>>tmpa>>tmpb;
            d[i].first = tmpb;
            d[i].second = tmpa;
        }
        sort(d,d+b+1);
        }
        // for(int i = 0;i<=b;i++) cout<<d[i].first<<" ";
        // cout<<"\n";
        // for(int i = 0;i<=b;i++) cout<<d[i].second<<" ";
        // cout<<"\n";
        for(int j = 1;j<=a;j++) {
            if(j >= d[1].first) c[1][j] = {d[1].second,1};
        }
        for(int i = 2;i<=b;i++) {
            for(int j = 1;j<=a;j++) {
                c[i][j] = c[i - 1][j];
                c[i][j].second = c[i - 1][j].second + 1;
                if(j - d[j].first>=0&&c[i - 1][j - d[j].first].first + d[j].second >= c[i - 1][j].first) {
                    c[i][j] = {c[i - 1][j - d[j].first].first,c[i - 1][j].second + 1};
                }
                // if(j >= d[j].first && c[i - 1][j - d[j].first].first + d[j].second <= j) c[i][j] = max(c[i - 1][j],c[i - 1][j - d[j].first] + d[j].second);
                // else c[i][j] = c[i - 1][j];
            }
        }
        for(int i = 0;i<=b;i++) {
            for(int j = 0;j<=a;j++) {
                cerr<<c[i][j].first<<" ";
            }
            cerr<<"\n";
        }
        cout<<c[b][a].first<<"\n";
    }
    return 0;
}