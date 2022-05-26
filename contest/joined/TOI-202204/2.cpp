// Author : ysh
// 04/28/2022 Thu 21:49:40.81
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a,b;cin>>a>>b;
    vector<int>f(a),c(b);
    for(int i = 0;i<a;i++) {
        cin>>f[i];
    }
    for(int i = 0;i<b;i++) {
        cin>>c[i];
    }
    sort(f.begin(),f.end());
    sort(c.begin(),c.end());
    int aa[a] = {},bb[b] = {},cc[a] = {};
    int siga,sigb;siga=sigb=0;
    for(int i = 0;i<a;i++) {
        auto now = lower_bound(c.begin(),c.end(),f[i]);
        int aaa = now - c.begin();
        aa[i] = aaa;
        siga += aa[i];
    }
    for(int i = 0;i<b;i++) {
        auto now = lower_bound(f.begin(),f.end(),c[i]);
        int aaa = now - f.begin();
        bb[i] = aaa;
        sigb += bb[i];
    }
    for(int i = 0;i<a;i++) {
        auto now = upper_bound(c.begin(),c.end(),f[i]);
        int aaa = now - c.begin();
        cc[i] = aaa;
    }
    // if(siga >= sigb) {
    //     for(int i = 0;i<a;i++) {
    //         if(aa[i] > 0 && aa[i] + siga > sigb + (b - cc[i])) {
    //             cout<<f[i]<<"\n";
    //             return 0;
    //         }
    //     }
    // }
    bool ok = 0;
    for(int i = a - 1;i>=0;i--) {
        // printf("i = %d,%d + %d > %d + (%d - %d)\n",i,siga,aa[i],sigb,b,cc[i]);
        if(siga + aa[i] > sigb + (b - cc[i]) && aa[i] != 0) {
            continue;
        } else {
            ok = 1;
            cout<<(i == a - 1 ? -1 : f[i + 1])<<"\n";
            break;
        }
    }
    if(!ok) cout<<f[0]<<"\n";
    // for(int i : aa) cout<<i<<" ";
    // cout<<"\n";
    // for(int i : bb) cout<<i<<" ";
    // cout<<"\n";
    // for(int i : cc) cout<<i<<" ";
    // cout<<"\n";
    return 0;
}