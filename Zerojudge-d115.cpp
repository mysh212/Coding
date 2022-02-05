#include<bits/stdc++.h>
using namespace std;
int pluss(int*,int);
void pc(int*,int);
int s = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a;
    while(cin>>a) {
    if(a == 0) return 0;
    s = a;
    int b[a],d[a] = {};
    for(int i = 0;i<a;i++) {
        cin>>b[i];
        d[i] = 1;
    }
    sort(b,b+a);
    int c;cin>>c;
    int t = 1;
    while(s != 0) {
        int tmp;
        if(t == 0) tmp = pluss(d,a-1);
        if(t == 1) t = 0;tmp = a;
        //pc(d,a);
        if(s != -1) {
            if(s != c) {
                continue;
            }
            for(int i = 0;i<a;i++) {
                if(d[i] == 1) {
                    cout<<b[i]<<" ";
                }
            }
            cout<<"\n";
        }
    }
    cout<<"\n";
    }
}
int pluss(int *a,int m) {
    if(a[m] == 1) {
        a[m] = 0;
        s -= 1;
        return s;
    }
    if(a[m] == 0&&m != 0) {
        a[m] = 1;
        s += 1;
        return pluss(a,m - 1);
    }
    return -1;
}
void pc(int *a,int m){
    cout<<s;
    for(int i = 0;i<m;i++) {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}