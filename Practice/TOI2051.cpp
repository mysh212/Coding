#include<bits/stdc++.h>
using namespace std;
int main() {
	//49 57  65 90
	deque<char>n;
	deque<int>m;
	deque<int>o;
	string a = "";
	cin>>a;
	int b = 0,c = 0;
	for(int i = 0;i<a.length();i++) {
		if(a.at(i) == '(') {
			b += 1;
			c = max(b,c);
		}
		if(a.at(i) == ')') {
			b -= 1;
		}
	}
	cout<<c;
} 
