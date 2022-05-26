#include<bits/stdc++.h>
using namespace std;
#define MAX 20000
vector<int>f(MAX,-1);
vector<int>ff;
//int last = 0;
int check(int);
int clone(int,int);
int sig = 0;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int a,b;cin>>a>>b;
	int n = sig = a;
	int tmpa,tmpb;
	iota(f.begin(),f.begin() + a,0);
	//for(int i : f) cout<<i<<" ";
	//return 0;
	for(int i = 0;i<b;i++) {
		cin>>tmpa>>tmpb;
		clone(tmpa,tmpb);
	}
	cin>>a>>b;
	for(int i = 1;i<=a;i++) {
		for(int j = 0;j<b;j++) {
			cin>>tmpa>>tmpb;
			ff.assign(f.begin(),f.end());
			clone(tmpa,tmpb);
			if(sig == 1) {
				f.assign(ff.begin(),ff.end());
				sig++;	
				cout<<i<<"\n";
			}
		}
	}
}
int check(int now) {
	if(f[now] == now) return now;
	return f[now] = check(f[now]);
}
int clone(int a,int b) {
	int aa = check(a);
	int bb = check(b);
	if(aa != bb) sig--;
	f[bb] = aa;
}
