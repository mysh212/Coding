#include<bits/stdc++.h>
using namespace std;
int check(int,int);
int ca();
int a,flag = 0;
int m[10000][10000] = {};
int vtd[10000] = {};
int main() {
    int b;cin>>a>>b;
    for(int i = 0;i<b;i++) {
        int tmpa,tmpb;cin>>tmpa>>tmpb;
        m[tmpa - 1][tmpb - 1] = 1;
    }
    (check(0,1) ? cout<<"No" : cout<<"Yes");
}
int check(int n,int r) {
	vtd[n] = 1;
    if(flag == 1&&n == 0&&ca()) return 1;
    if(r == 2000000) return 0;
    flag = 1;
    for(int i = 0;i<a;i++) {
        if(m[n][i] == 1) {
            cout<<"["<<n<<"]["<<i<<"]\n";
            if(check(i,r + 1)) return 1;
        }
    }
    return 0;
}
int ca() {
	for(int i = 0;i<a - 1;i++) {
		cout<<vtd[i];
		if(vtd[i] == 0) return 0;
	}
	return 1;
}
