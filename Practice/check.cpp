#include<bits/stdc++.h>
using namespace std;
int t = 0;
void test(int,int,int);
int main() {
	for(int i = 1;i<=100;i++) {
		test(i,1,i);
	} 
	//cout<<t<<" times.";
}
void test(int n,int c,int i) {
	if(n==1) {
		return;
	}
	if(c == 100) {
		cout<<i<<"\t";
		t++;
		return;
	}
	if(n == 0) {
		//cout<<i<<1<<"\t";
		return;
	}
	if(n % 2 == 1&&n / 10 != 0) {
		test(n % 10 + n / 10,c + 1,i);
		return;
	}
	if(n % 2 == 0&&n / 10 != 0) {
		test((n % 10) * 10 + (n / 10),c + 1,i);
		return;
	}
	if(n / 10 == 0) {
		test(n * 3 - 2,c + 1,i);
		return;
	}
}
