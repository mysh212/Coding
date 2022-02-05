#include<iostream>
using namespace std;
int fes(int);
int t = 0;
int main() {
	int a = 0;
	cin>>a;
	cout<<fes(a);
	cout<<" "<<t;
}
int fes(int n) {
	t = t + 1;
	if(n == 1||n == 0) {
		return n;
	}
	return fes(n - 1) + fes(n - 2);
}
/*
#include<iostream>
using namespace std;
int times = 0;
int fes(int);
int fest(int);
int main() {
	int a = 0;
	cin>>a;
	cout<<fes(a)<<" "<<fest(a);
}
int fes(int n) {
	times = times + 1;
	if(n == 1||n == 2) {
		return 1;
	}
	return fes(n - 1) + fes(n - 2);
}
int fest(int n) {
	times = times + 1;
	if(n == 1||n == 0) {
		return 1;
	}
	return fest(n - 1) + fest(n - 2) + 1;
}
*/
