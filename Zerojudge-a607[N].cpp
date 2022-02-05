#include<bits/stdc++.h>
using namespace std;
int check(int,int,int);
int mf[10001] = {0}; 
int main() {
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int m,n;cin>>n>>m;
	for(int i = 0;i<n;i++) {
		cin>>mf[i];
	}
	cout<<check(0,m,n);
}
int check(int a,int m,int n) {
	int tmp = 0;
	for(int i = 0;i<=min(m,mf[a]);i++) {
		//cout<<"["<<a<<","<<i<<"] ";
		if(m == i) {
			tmp += 1;
			break;
		}
		if(a + 1 == n) {
			if(min(m,mf[a]) == m) {
				tmp += 1;
			}
			break;
		} 
		tmp += check(a + 1,m - i,n);
		tmp = tmp % 1000007;
	} 
	return tmp; 
}
