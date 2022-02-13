// Author : ysh
// 02/13/2022 Sun 16:29:04.40
#include<bits/stdc++.h>
using namespace std;
#define g "Gunjyo"
#define k "Koying"
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a,b;cin>>a>>b;
    if(a%2==1||a%2==-1) cout<<"Odd\n";
    else cout<<"Even\n";
    if(b%2==1||b%2==-1) cout<<"Odd\n";
    else cout<<"Even\n";
    bool aa,bb;
    //cout<<a % 2<<" "<<b % 2<<"\n";
    aa = (bool) (a % 2 == 1||a % 2 == -1);
    bb = (bool) (b % 2 == 1||b % 2 == -1);
    //cout<<(int)aa<<" "<<(int)bb<<"\n";
    if(aa == 1&&bb == 0) {
        cout<<g;
        return 0;
    }
    if(aa == 0&&bb == 1) {
        cout<<k;
        return 0;
    }
    if(a < b) {
        cout<<k;
        return 0;
    }
    cout<<g;
    return 0;
}