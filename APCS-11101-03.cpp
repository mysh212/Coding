// Author : ysh
// 01/10/2022 Mon 11:19:39.61
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<string>f(n);
    for(int i = 0;i<n;i++) {
        cin>>f[i];
    }
    sort(f.begin(),f.end());
    int ans = 0;
    for(string i : f) {
        int l = i.size();
        for(int j = 1;(j * 2) < l;j++) {
            if(i.substr(0,j) == i.substr(l - j)) {
                //printf("if %s == %s then find %s\n",i.substr(0,j).c_str(),i.substr(l - j).c_str(),i.substr(j,l-(j*2)).c_str());
                if(binary_search(f.begin(),f.end(),i.substr(j,l-(j*2))) == true) {
                    //printf("!");
                    ans++;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}