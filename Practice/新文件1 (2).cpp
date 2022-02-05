#include<bits/stdc++.h>
using namespace std;
int main() {
	int r = 200;
	int count = 0;
	for(int i = 0;i<=r;i++) {
		for(int j = 0;j<=r;j++) {
			for(int k = 0;k<=r;k++) {
				for(int l = 0;l<=r;l++) {
					if(i<=j&&j<=k&&k<=l) {
						count++;
						cout<<"("<<i<<"\t"<<j<<"\t"<<k<<"\t"<<l<<")\t"<<count<<"\n";
					} 
				} 
			} 
		} 
	} 
	cout<<count;
	return 0;
} 
