#include<iostream>
#include<algorithm>
#include<cstring>
#include<sstream>
#include<math.h>
using namespace std;
int main() {
	/*
	string a="This is is is is ising is is Is isisisis a test stringing :)";
	string b="test :)";
	//getline(cin,a);
////	swap(a,b);
	int p;
	p = a.find("is"); 
//	do {
//		a.replace(p,2,"at");
//		cout<<a<<"\n";
//		p = a.find("is"); 
//	} while(p!=-1);

////	cout<<a<<"\t"<<b<<"\t"<<p;


//////	a = a + " " + b;
//////	cout<<a;
	*/
	
	long long tmp = 0;
	string a;
	while(getline(cin,a)) {
		stringstream b;
		b << a;
		long long ans = 0;
		while(b>>tmp) {
			ans += tmp;
			tmp = 0;
		}
	 	cout<<ans<<" ";
	}

}
