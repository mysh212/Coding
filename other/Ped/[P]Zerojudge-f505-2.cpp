// Author : ysh
// 01/21/2022 Fri 19:50:06.46
#include<bits/stdc++.h>
using namespace std;
#define int long long
queue<pair<int,pair<int,pair<int,int>>>>f;
int r[205][205] = {};
void check(int,int,int,int);
void pour(int,int,int,int,int,int);
int aaa,bbb,ccc,ddd,ta,tb,tc,mmax,mmaxw,tmp;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    aaa=bbb=ccc=ddd=ta=tb=tc=mmax=mmaxw=tmp=0;
    cin>>tmp;
    while(tmp != 0) {
        mmax=mmaxw=aaa=bbb=ccc=ddd=tc=tb=tc=0;
        bool had=0;
        int a,b,c,d;cin>>a>>b>>c>>d;
        ta=a;tb=b;tc=c;
        f.emplace(make_pair(0,make_pair(0,make_pair(c,0))));
        if(c < d) {
            cout<<"0 "<<c<<"\n";
            f.pop();
            tmp--;
            continue;
        }
        if(c == d) {
            cout<<"0 "<<d<<"\n";
            f.pop();
            tmp--;
            continue;
        }
        while(!f.empty()) {
            auto aa=f.front();f.pop();
            auto bb=aa.second;
            auto cc=bb.second;
            int a=aa.first;
            int b=bb.first;
            int c=cc.first;
            int n=cc.second;
            printf("[%d,%d,%d,%d]\n",a,b,c,n);
            system("pause");
            if(a<=d&&a>mmax) {
                mmax = a;mmaxw=n;
            }
            if(b<=d&&b>mmax) {
                mmax = b;mmaxw=n;
            }
            if(c<=d&&c>mmax) {
                mmax = c;mmaxw=n;
            }
            if((c == mmax||b == mmax||a == mmax) && n < mmaxw) {
                mmaxw = n;
            }
            check(a,b,c,n);
        }
        while(!f.empty()) f.pop();
        if(had == 0) cout<<mmaxw<<" "<<mmax<<"\n";
        tmp--;
        continue;
    }
    return 0;
}
void check(int a,int b,int c,int n) {
    if(r[a][b]==tmp) {
        return;
    }
    r[a][b] = tmp;
    //1.A->B
    pour(b,a,c,tb,ta,tc);
    f.emplace(make_pair(bbb,make_pair(aaa,make_pair(ccc,n+ddd))));
    //2.B->A
    pour(a,b,c,ta,tb,tc);
    f.emplace(make_pair(aaa,make_pair(bbb,make_pair(ccc,n+ddd))));
    //3.A->C
    pour(c,a,b,tc,ta,tb);
    f.emplace(make_pair(bbb,make_pair(ccc,make_pair(aaa,n+ddd))));
    //4.B->C
    pour(c,b,a,tc,tb,ta);
    f.emplace(make_pair(ccc,make_pair(bbb,make_pair(aaa,n+ddd))));
    //5.C->A
    pour(a,c,b,ta,tc,tb);
    f.emplace(make_pair(aaa,make_pair(ccc,make_pair(bbb,n+ddd))));
    //6.C->B
    pour(b,c,a,tb,tc,ta);
    f.emplace(make_pair(ccc,make_pair(aaa,make_pair(bbb,n+ddd))));
    return;
}
void pour(int a,int b,int c,int ta,int tb,int tc) {
    if(a != ta) {
        if(ta-a > b) {
            ddd=b;
            a = a + b;
            b = 0;
        } else {
            ddd=ta - a;
            b = b - (ta - a);
            a = ta;
        }
    } else {
        aaa=a;
        bbb=b;
        ccc=c;
        ddd=0;
        return;
    }
    aaa=a;
    bbb=b;
    ccc=c;
    return;
}