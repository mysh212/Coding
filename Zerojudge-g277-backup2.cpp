#include<bits/stdc++.h>
using namespace std;
int low(int,int,long long int*);
long long sig(int,int,long long int*);
void pc(int,int,long long int*);
long long test(int,int,long long int*,long long int*);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    long long a[n+1] = {0};
    long long b[n+1] = {0};
    for(int i = 1;i<=n;i++) {
        cin>>a[i];
        b[i] = b[i-1] + a[i];
    }
    cout<<test(1,n,a,b);
}
long long test(int l,int r,long long int *a,long long int *b) {
    //pc(l,r,a);
    while(l != r) {
        int ll=low(l,r,a);
        if(b[ll-1] - b[l-1]>b[r] - b[ll]) {
            r=ll-1;
        } else {
            l=ll+1;
        }
    }
    return a[l];
}
int low(int l,int r,long long int *a) {
    long long tmp = a[l];
    int ans=l;
    for(int i = l;i<=r;i++) {
        if(a[i]<tmp) {
            tmp = a[i];
            ans = i;
        }
    }
    return ans;
}
void pc(int l,int r,long long int *a) {
    long long tmp = a[l],ans=l;
    for(int i = l;i<=r;i++) {
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
long long sig(int l,int r,long long int *a) {
    return a[r] - a[l-1];
}
