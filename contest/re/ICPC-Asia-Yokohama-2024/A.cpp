// Author : ysh
// 2026/11/05 Thu 14:44:01
#include<bits/stdc++.h>
using namespace std;
int ans = 0;
void f(int l,int r,vector<int> &used,vector<int> &arr){
    int k=0,be;
    for(int i=l;i<=r;i++){
        if(k==0 && arr[i]>used[i]){be = i;k = arr[i];}
        else if(arr[i] < k && arr[i] != used[i]) k = arr[i];
        else if(used[i]==arr[i]){
            for(int j=be;j<i;j++) used[j] = k;
            k = 0;
            f(be,i-1,used,arr);
            ans++;
        }
    }
    if(k!=0){
        for(int i=be;i<=r;i++) used[i] = k;
        ans++;
        f(be,r,used,arr);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    vector<int> arr(n),used(n,0);
    for(int i=0;i<n;i++) cin>>arr[i];
    int k = 0;
    f(0,n,used,arr);
    cout<<ans;
    cout<<'\n';
    for(int i=0;i<n;i++) cout<<used[i];
}