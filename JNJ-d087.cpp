#include<iostream>
#include<string.h>
using namespace std;
int main() {
	int a;cin>>a;
	int b[a];
	int c[a];
	for(int i = 0;i<a;i++) {
		cin>>b[i]>>c[i];
	}
	int d = b[0];
	int tmp = 0,ttmp = 0;
	int mmax = 0;
	for(int j = 0;j<a;j++) {
		if(d<b[j]) {
			d = b[j];
		}
		d += c[j];
		tmp = j + 1;
		while(b[tmp]<=d&&tmp<a) {
			ttmp += 1;
			tmp += 1;
		}
		mmax = max(mmax,ttmp);
		ttmp = 0;
		tmp = 0;
	}
	cout<<mmax;
}
