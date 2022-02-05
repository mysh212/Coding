#include<bits/stdc++.h>
using namespace std;
int check(char a);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int k;cin>>k;
    string a;cin>>a;
    int s = check(a.at(0));
    int len = 0,llen = 0;
    int mmax = 0;
    for(int i = 0;i<a.length();i++) {
        int tmp = check(a.at(i));
            //k = 3
            //1. TTTrrrT'T'
            //2. TTTrrrTT'T'
            //3. TTTrrrTTT'r'
            //4. TTTrrrTTT'T'
            //1,2.
            //cout<<s<<" "<<len<<" "<<llen<<" "<<tmp<<"\n";
            if(s == tmp&&llen<k) {
                llen++;
                //cout<<len;
                continue;
            }
            //3.
            if(s != tmp&&llen == k) {
                s = tmp;
                len += llen;
                llen = 1;
                //cout<<len;
                continue;
            }
            //4.
            if(llen>=k&&len != 0) {
                if(llen == k) {
                    mmax = max(mmax,len + llen);
                }
                mmax = max(mmax,len);
                len=llen;s=tmp;
                //cout<<len;
                continue;
            }
            if(s != tmp) {
                mmax = max(mmax,len);
                llen=1;len=0;s=tmp;
                //cout<<len;
                continue;
            }
            //cout<<len;
    }
    mmax = max(mmax,len);
    cout<<mmax<<"\n";
}
int check(char a) {
    if(a>='A'&&a<='Z') return 1;
    if(a>='a'&&a<='z') return 0;
    return -1;
}