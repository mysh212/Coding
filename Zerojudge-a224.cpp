// Author : ysh
// 03/28/2022 Mon 17:55:11.96
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a;
    while(cin>>a) {
        map<char,bool>f;
        for(auto i : a) {
            if(!((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))) continue;
            char j = i;
            if(i >= 'A' && i <= 'Z') {
                j = i - ('A' - 'a');
            }
            auto found = f.find(j);
            if(found == f.end()) {
                f.insert({j,1});
                // printf("%c",j);
                continue;
            }
            f[j] = !f[j];
        }
        // printf("\n");
        bool j = 0;
        bool nf = 0;
        for(auto i : f) {
            if(i.second == 1) {
                if(j == 0) {
                    j = 1;
                } else {
                    nf = 1;
                    break;
                }
            }
        }
        // for(auto i : f) printf("%c:%d ",i.first,(int) i.second);
        // printf("\n");
        cout<<(nf ? "no..." : "yes !")<<"\n";
    }
    return 0;
}