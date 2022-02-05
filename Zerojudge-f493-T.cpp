#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("1.txt","w",stdout);
	int a;cin>>a;
	cout<<a<<" "<<a<<"\n";
	srand(time(NULL));
	for(int i = 1;i<=a;i++) {
		for(int j = 1;j<=a;j++) {
			if(rand() % 2 == 1) {
				cout<<'W';
			} else {
				cout<<'#';
			}
		}
		cout<<"\n";
	} 
}
