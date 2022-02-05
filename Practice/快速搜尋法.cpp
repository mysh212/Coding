#include<bits/stdc++.h>
using namespace std;
void sorting(int,int*,int);
int main() {
	int n;cin>>n;
	int a[n] = {};
	for(int i = 0;i<n;i++) {
		cin>>a[i];
	}
}
void sorting(int start,int *a,int end) {
	int pivot=0;
	pivot=a[end/2];
	int i = 0;
	if(end-start<=1) {
		if(a[end]<a[start]) {
			swap(a[end],a[start]);
		}
		return;
	} else {
		sorting(start,a,end/2);
		sorting(end/2,a,end);
		int tmp[end-start+1],n=0;
		for(int i = start;i<=end/2;i++) {
			int j=i;
			while(1) {
				if(a[j-start+(end/2)]<a[i]) {
					tmp[n]=a[j-start+(end/2)];
					j++;
				} else if (a[j-start+(end/2)]==a[i]) {
					
				} else {
					break;
				}
			}
		}
	}
}
