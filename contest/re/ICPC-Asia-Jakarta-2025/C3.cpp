// Author : ysh
// 2026/10/29 Thu 19:05:37
#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    if(m%2 == 0){
        for(int i=0;i<n;i++){
            if(arr[i] > m/2){
                cout<<-1;
                return 0;
            }
        }
        int mark = 0;
        for(int i=0;i<n;i++){
            int num=0;
            for(int j=0;j<m;j++){
                if( j%2 == mark && num<arr[i]){
                    cout<<1;num++;
                }else cout<<0;
            }
            mark = (mark+1)%2;
            cout<<'\n';
        }
    }else{
        vector<int> state(n,-1);
        for(int i=0;i<n;i++){
            if(arr[i] == m/2+1){
                state[i]=1;
                for(int j=i-1;j >= 0;j--){
                    if(arr[j+1]+arr[j] <= m/2+state[j+1]) break;
                    int tmp = (state[j+1]+1)%2;
                    if(state[j] != -1 && state[j] != tmp){
                        cout<<-1;return 0;
                    }
                    state[j] = tmp;
                }
                for(int j=i+1;j < n;j++){
                    if(arr[j-1]+arr[j] <= m/2+state[j-1]) break;
                    int tmp = (state[j-1]+1)%2;
                    if(state[j] != -1 && state[j] != tmp){
                        cout<<-1;return 0;
                    }
                    state[j] = tmp;
                }
            }
        }
        for(int i=0;i<n;i++){
            int num = 0;
            if(i > 0 && state[i]==-1) state[i] = (state[i-1]+1)%2;
            else if(state[i]==-1) state[i] = 1;
            if(i > 0 && state[i] == state[i-1] && state[i] != -1){
                if(state[i]){
                    int now = arr[i]*2;int num = 0;
                    for(int j=0;j<now;j++) cout<<0;
                    for(;now<m;now++){
                        if(now%2 == 0 && num < arr[i]){cout<<1;num++;}
                        else cout<<0;
                    }
                }
                else{
                    int now = arr[i]*2+1;int num = 0;
                    for(int j=0;j<num;j++) cout<<0;
                    for(;now<m;now++){
                        if(now%2 && num < arr[i]){cout<<1;num++;}
                        else cout<<0;
                    }
                }
            }
            else if(state[i] == 1){
                for(int j=0,num = 0;j<m;j++){
                    if( j%2==0 && num < arr[i]){cout<<1;num++;}
                    else cout<<0;
                }
            }
            else{
                for(int j=0,num=0;j<m;j++){
                    if(j%2 && num < arr[i]){cout<<1;num++;}
                    else cout<<0;
                }
            }
            cout<<'\n';
        }
    }
}