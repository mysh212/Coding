#include<iostream>
#include<math.h>
using namespace std;
int main() {
	cout<<"2\t3\t"; 
	for(int i = 4;i<=2000;i++) {
		for(int j = 2;j<=sqrt(i);j++) {
			if(i % j == 0) {
				break;
			}
			if(j + 1>sqrt(i)) {
				cout<<i<<"\t";
				
			}
		}
	}
}
