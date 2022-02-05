#include<bits/stdc++.h>
using namespace std;
int main() {
	string a;
	getline(cin,a);
	cout<<"Interval:";
	for(int m = 0;m<26;m++) {
		for(int i = 0;i<a.size();i++) {
			if(a.at(i) == ' ') {
				cout<<" ";
				continue;
			}
			int n = (int) a.at(i) - m;
			if(n < 97) {
				n += 26;
			}
			cout<<(char) n;
		}
		cout<<"\n";
	}
	system("pause");
	return 0;
}
