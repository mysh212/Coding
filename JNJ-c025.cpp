#include<iostream>
#include<string.h>
using namespace std;
int main() {
	string a;cin>>a;
	string b;cin>>b;
	int p,c,h;p=c=h=0;
	int mmax = 0;
	for(int i = 0;i<a.size();i++) {
		if(a.at(i) == b.at(i)&&a.at(i)!='-') { //�����šA���� 
			c += 1;
			p += c * 100;
			h += 1;
		}
		if(a.at(i) != b.at(i)&&a.at(i)!='-') { //�����A�ӥB���঳����!!! 
			c = 0;
			h = h - 3;
		}
		mmax = max(mmax,c);
		if(h < 0) {
			h = 0;
		}
		//cout<<p<<" "<<c<<" "<<h<<"\n";
	}
	cout<<p<<" "<<mmax<<" "<<h;
	return 0;
}
