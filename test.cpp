// Author : ysh
// 2025/05/24 Sat 21:08:32
#include<bits/stdc++.h>
using namespace std;
// #include<heap>
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    printf("Please input starting city number: ");
    int a;scanf("%d", &a);a--;
    printf("Please input destination city number: ");
    int b;scanf("%d", &b);b--;
    // The shortest distance from 1 to 6 is 13 
    // The shortest path: 1 > 2 > 3 > 5 > 4 > 6

    int n, m;n = m = 0;
    vector<vector<pair<int,int>>>f;
    ifstream in("0.in");
    {
        vector<array<int, 3>>pre;
        int a, b, c;
        while(in >> a >> b >> c) {
            n = max({n, a, b});
            m++;
            a--;b--;
            pre.push_back({a, b, c});
            pre.push_back({b, a, c});
        }
        f.resize(n);
        for(auto &i : pre) f.at(i[0]).push_back({i[1], i[2]});
    }

    vector<bool>mark(n);
    vector<int>re(n);
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>q;
    q.push({0, -1, a});
    while(!q.empty()) {
        auto now = q.top(); q.pop();
        int l = now[0];
        int last = now[1];
        int d = now[2];
        
        if(mark.at(d)) continue;
        mark.at(d) = 1;
        re.at(d) = last;

        if(d == b) {
            printf("The shortest distance from %d to %d is %d\n", a + 1, b + 1, l);
            break;
        }
        
        for(auto &i : f.at(d)) {
            q.push({l + i.second, d, i.first});
        }
    }

    // for(int &i : re) cout<<i<<" ";

    vector<int>ans;
    int d = b;
    while(d != a) ans.push_back(d), d = re.at(d);

    reverse(ans.begin(), ans.end());
    printf("The shortest path: %d", a + 1);
    for(int &i : ans) printf(" > %d",i + 1);

    return 0;
}