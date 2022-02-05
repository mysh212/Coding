#include<bits/stdc++.h>
using namespace std;
int check(string);
void run(int*,int);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int aa;cin>>aa;
    string c;cin>>c;
    int q = 0;
    int ans = 0;
    for(int i = 0;i<c.length();i++) {
        if(c.at(i) == '?') {
            q += 1;
        }
    }
    int b[q] = {};
    for(int j = 0;j<pow(2,q);j++) {
        //cout<<1;
        //for(int i = 0;i<q;i++) cout<<b[i]<<" ";
        string d = c;
        for(int i = 0;i<q;i++) {
            if(b[i] == 1) d = d.replace(d.find('?'),1,"[");
            if(b[i] == 0) d = d.replace(d.find('?'),1,"]");
        }
        if(check(d) == 1) {
            //cout<<d<<"\n";
            ans++;
        }
        run(b,q - 1);
    }
    cout<<ans;
}
void run(int *a,int n) {
    if(a[n] == 1) {
        a[n] = 0;
        if(n == 0) return;
        run(a,n - 1);
        return;
    } else if (a[n] == 0) {
        a[n] = 1;
        return;
    }
}
int check(string c) {
    int tmp = 0;
    for(int i = 0;i<c.length();i++) {
        if(c.at(i) == '[') {
            tmp ++;
        } else {
            tmp--;
        }
        if(tmp < 0) return 0;
    }
    if(tmp == 0) return 1;
    else return 0;
}