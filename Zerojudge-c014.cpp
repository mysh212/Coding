// Author : ysh
// 2024/12/11 Wed 20:45:37
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a,b;
    while(cin>>a>>b, (a != "0" || b != "0")) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        int aa = a.size();
        int bb = b.size();

        if(aa < bb) swap(a,b), swap(aa,bb);

        int aans = 0;
        bool last = 0;
        for(int i = 0;i<aa;i++) {
            int left = (i >= aa ? 0 : a.at(i) & 15);
            int right = (i >= bb ? 0 : b.at(i) & 15);

            int ans = left + right + (last ? 1 : 0);
            if(ans >= 10) aans++, last = 1;
            else last = 0;
        }

        if(aans == 0) cout<<"No carry operation.";
        else if(aans == 1) cout<<"1 carry operation.";
        else cout<<aans<<" carry operations.";

        cout<<"\n";
    }
    return 0;
}