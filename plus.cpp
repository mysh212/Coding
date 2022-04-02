// Author : ysh
// 04/02/2022 Sat  9:51:16.66
// https://192.168.193.20/problem/18
#include<bits/stdc++.h>
#define p system("pause");
using namespace std;
int main() {
    //freopen("18\\T\\5.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a = "";getline(cin,a);
    int n = stoi(a);
    string tmp = "";
    while(n--) {
        getline(cin,tmp,'\n');
        //p
        stringstream s;
        s << tmp;
        string a = "",b = "";
        vector<int>f(100);
        s >> a;
        for(int i = a.size() - 1;i>=0;i--) {
            string tmp = a.substr(i,1);
            f[(a.size() - 1) - i] = stoi(tmp);
        }
        while(s >> b) {
            int hold = 0;
            for(int i = b.size() - 1;i>=0;i--) {
        // cout<<hold<<endl;
        // for(int i : f) cout<<i;
        // cout<<"\n";
                string tmp = b.substr(i,1);
                f[(b.size() - 1) - i] += stoi(tmp) + hold;
                hold = f[(b.size() - 1) - i] / 10;
                f[(b.size() - 1) - i] = f[(b.size() - 1) - i] % 10;
            }
            if(hold != 0) {
                int i = b.size();
                while(hold != 0) {
                    f[i] += hold;
                    hold = f[i] / 10;
                    f[i] = f[i] % 10;
                    i++;
                }
            }
        }
        bool c = 0;
        for(int i = f.size() - 1;i >= 0;i--) {
            if(f[i] == 0) {
                if(!c) continue;
            }
            c = 1;
            cout<<f[i];
        }
        if(!c) cout<<0;
        cout<<"\n";
    }
    return 0;
}