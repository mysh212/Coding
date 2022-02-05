#include<iostream>
#include<string.h>
using namespace std;
int main() {
	string a;cin>>a;
	int b,c;b=c=0;
	for(int i = 0;i<a.length();i++) {
		if(a.at(i) == 'F') {
			b += 1;
		}
		if(a.at(i) == 'f') {
			c = max(b,c);
			b = 0;
		}
	}
	c = max(b,c);
	cout<<c;
}
