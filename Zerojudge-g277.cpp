#include<bits/stdc++.h>
using namespace std;
int low(int,int,long long int*);
long long sig(int,int,long long int*);
void pc(int,int,long long int*);
long long test(int,int,long long int*,long long int*);
int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int n;cin>>n;
    long long a[n+1] = {0};
    long long b[n+1] = {0};
    pair<long long,int> c[n+1] = {};
    for(int i = 1;i<=n;i++) {
        cin>>a[i];
        c[i] = make_pair(a[i],i);
        b[i] = b[i-1] + a[i];
    }
    sort(c+1,c+n+1);
    for(int i = 1;i<=n;i++) {
        //cout<<c[i].first<<" ";
    }
    //cout<<"\n";
    deque<pair<long long,int>> q;
    for(int i = 1;i<=n;i++) {
        //cout<<c[i].second<<" ";
        q.emplace_back(make_pair(c[i].first,c[i].second));
    }
    /*
    for(int i = 1;i<=n;i++) {
        auto tmp = q.front();
        cout<<tmp.first<<" "<<tmp.second<<"\n";
        q.pop_front();
    }
    */
        //pc(l,r,a);
        int l,r;l=1;r=n;
    while(l != r) {
        auto tmp = q.front();
        if(!(tmp.second<=r&&tmp.second>=l)&&!(q.empty())) {
            q.pop_front();
            tmp = q.front();
        }
        //cout<<l<<" "<<tmp.first<<" "<<tmp.second<<" "<<r<<"\n";
        q.pop_front();
        int ll=tmp.second;
        if(b[ll-1] - b[l-1]>b[r] - b[ll]) {
            r=ll-1;
        } else {
            l=ll+1;
        }
    }
    cout<<a[l];
    //cout<<test(1,n,a,b);
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
