#include<iostream>
#include<string.h>
using namespace std;
int main() {
	string a;cin>>a;
	string b;
	int brk = 1;
	for(int i = 3;i<=6;i++) {
		if(i * 2 > a.size()) {
			break;
		}
		b = a.substr(0,i);
		for(int j = 0;j<a.size();j++) {
			if(a.at(j) != b.at(j % i)) {
				brk = 0;
				break;
			}
		}
		if(brk == 1) {
			cout<<i;
			return 0;
		}
		brk = 1;
	}
	cout<<0;
	return 0;
}
