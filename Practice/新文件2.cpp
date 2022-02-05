#include<bits/stdc++.h>
using namespace std;
int main() {
	int a[10] = {9,15,35,46,56,78,88,98,99,100};
	int b = 0;
	cin>>b;
	/*
	 ^
Vh   |       /
	 |      /
	 |     /
A    |    /
	 |   /
Vd   |  /
	 |_______________________\
	       nd     nA     nh
	       ==> (Vh - Vd) / (A - Vd) = (nh - nd) / (nA - nd)
	       ==> nA = (nh - nd) X (A - Vd) / (Vh - Vd) + nd
	       ==>  nh = 9
	    		nd = 0
	    		Vh = 9
	    		Vd = 0
	*/
	sort(a,a+10);
	//max = a[9]
	//min = a[0]
	int max = a[9];
	int min = a[0];
	int mmax = 9;
	int mmin = 0;
	while(1) {
		if(a[(mmax - mmin) * (b - min) / (max - min) + mmin] > b) {
			mmax = (mmax - mmin) * (b - min) / (max - min) + mmin;
			max = a[(mmax - mmin) * (b - min) / (max - min) + mmin];
		} else if(a[(mmax - mmin) * (b - min) / (max - min) + mmin] < b) {
			mmin = (mmax - mmin) * (b - min) / (max - min) + mmin;
			min = a[(mmax - mmin) * (b - min) / (max - min) + mmin];
		} else {
			break;
		}
	}
	cout<<(mmax - mmin) * (b - min) / (max - min) + mmin;
}
