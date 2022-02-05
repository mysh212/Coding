#include<bits/stdc++.h>
using namespace std;
void p(int*,int,int);
int main() {
	int a=0;
	int n;cin>>n;
	p(&a,n,1);
	cout<<a;
	return 0;
}
void p(int *a,int n,int now) {
	*a = *a + now;
	if(n==now) {
		return;
	} else {
		now += 1;
		p(a,n,now);
	}
}
