// Author : ysh
// 01/21/2022 Fri 19:50:06.46
#include<bits/stdc++.h>
using namespace std;
#define int long long
struct water {
    long long a,b,c,n;
};
queue<water>f;
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
        f.push({0,0,c,0});
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
            int a=aa.a;
            int b=aa.b;
            int c=aa.c;
            int n=aa.n;
            // printf("[%d,%d,%d,%d]\n",a,b,c,n);
            // system("pause");
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
    f.push({bbb,aaa,ccc,n+ddd});
    //2.B->A
    pour(a,b,c,ta,tb,tc);
    f.push({aaa,bbb,ccc,n+ddd});
    //3.A->C
    pour(c,a,b,tc,ta,tb);
    f.push({bbb,ccc,aaa,n+ddd});
    //4.B->C
    pour(c,b,a,tc,tb,ta);
    f.push({ccc,bbb,aaa,n+ddd});
    //5.C->A
    pour(a,c,b,ta,tc,tb);
    f.push({aaa,ccc,bbb,n+ddd});
    //6.C->B
    pour(b,c,a,tb,tc,ta);
    f.push({ccc,aaa,bbb,n+ddd});
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