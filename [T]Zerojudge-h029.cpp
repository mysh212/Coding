// Author : ysh
// 03/04/2022 Fri  8:18:27.34
#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("1.in","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    srand(time(NULL));
    int a,b;cin>>a>>b;
    cout<<1<<" "<<b<<"\n";
    for(int i = 0;i<a;i++) {
        cout<<rand() % 10<<" ";
    }
    cout<<"\n";
    for(int i = 0;i<b;i++) {
        cout<<rand() % 10<<" ";
    }
    cout<<"\n";
    vector<bool>f(a*2+1);
    f[1] = 1;
    for(int i = 1;i<a;i++) {
        int tmpa,tmpb;
        while(1) {
            tmpa = rand()% (a*2+1);
            if(f[tmpa]!=1&&tmpa!=i&&tmpa>=1&&tmpa<=(a*2-1)) {
                f[tmpa] = 1;
                break;
            }
        }
        while(1) {
            tmpb = rand()% (a*2+1);
            if(f[tmpb]!=1&&tmpb!=i&&tmpb>=1&&tmpb<=(a*2-1)) {
                f[tmpb] = 1;
                break;
            }
        }
        cout<<i<<" "<<tmpa<<" "<<tmpb<<"\n";
    }
}