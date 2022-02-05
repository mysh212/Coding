#include<iostream>
#include<string.h>
using namespace std;
int main() {
	int a,b;cin>>a>>b;
	int tmp3; //保留不足十點
	tmp3 = b % 10;
	b = b - tmp3;
	int tmp1,tmp2;tmp1=tmp2=0;
	tmp2 = a / 100 * 10;  //要扣的點數 
	if(tmp2>=b) {
		a = a - b;
		b = 0;
	} else {
		b = b - tmp2;
		a = a - tmp2;
	}
	b = b + tmp3;
	tmp1 = a / 100;
	b = b + tmp1;
	cout<<a<<" "<<b;
}
