#include<bits/stdc++.h>
using namespace std;
int check(int,int,int);
int mf[200001] = {0}; 
int main() {
    //freopen("1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int m,n,r;cin>>n>>m>>r;
    m = m % n;
    int x = 0; 
    while(1) {
    	x += m;
    	x = (x - 1) % n + 1; 
		mf[x] = 1; 
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
