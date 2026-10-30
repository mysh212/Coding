// Author : ysh
// 2026/10/29 Thu 17:11:56
#include<bits/stdc++.h>
using namespace std;

void solve(int n,vector<int> &arr,vector<int> &ans){
    int now = 1;
    for(int i=0;i<n;i++,now++){
        if(arr[i] >= now) ans[i] = now;
        else{
            ans[i] = arr[i];
            for(int tmp = arr[i]+1,j = i-1;tmp < ans[j];j--,tmp++){
                ans[j] = tmp;
                //cout<<1<<'\n';
            }
            now = arr[i]+1;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    vector<int> arr(n);
    vector<int> left_ans(n),right_ans(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int now = 0;
    solve(n,arr,left_ans);
    reverse(arr.begin(),arr.end());
    solve(n,arr,right_ans);
    reverse(right_ans.begin(),right_ans.end());
    int ans = -1;
    for(int i=0;i<n;i++){
        ans = max(ans,min(left_ans[i],right_ans[i]));
    }
    cout<<ans;
}