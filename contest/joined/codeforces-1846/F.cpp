// Author : ysh
// 2023/07/08 Sat 00:04:33
#include<bits/stdc++.h>
using namespace std;
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;cin>>n;
    while(n--) {
        int n;cin>>n;
        vector<int>f(10);
        for(int i = 0;i<n;i++) {
            int tmp;cin>>tmp;
            f.at(tmp)++;
        }
        cout<<"- 0"<<endl<<flush;
        for(int i = 0;i<n;i++) {
            int tmp;cin>>tmp;
        }
        cout<<"- 0"<<endl<<flush;
        vector<int>v(10);
        vector<int>pre(n);
        for(int i = 0;i<n;i++) {
            int tmp;cin>>tmp;
            pre.at(i) = tmp;
            v.at(tmp)++;
        }
        int ans = 0;
        for(int i = 0;i<10;i++) {
            if(v.at(i) > f.at(i)) ans = i;
        }
        vector<int>tmp;
        for(int i = 0;i<n;i++) {
            if(pre.at(i) != ans) tmp.push_back(i + 1);
        }

        cout<<"- "<<tmp.size()<<" ";
        for(int &i : tmp) cout<<i<<" ";
        cout<<""<<endl<<flush;
        for(int i = 0;i < n - tmp.size();i++) {
            int tmp;cin>>tmp;
        }

        cout<<"- 0"<<endl<<flush;
        for(int i = 0;i<n - tmp.size();i++) {
            int tmp;cin>>tmp;
            if(tmp != ans) cout<<"! "<<i + 1<<""<<endl<<flush;
        }
    }
    return 0;
}