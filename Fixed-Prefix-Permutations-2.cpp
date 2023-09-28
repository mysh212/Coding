// Author : ysh
// 2023/06/19 Mon 20:31:03
#include<bits/stdc++.h>
using namespace std;
struct box{
    vector<box*>next;
    box() {
        next.resize(10);
    }
};
int a,b;
box root;
void insert(vector<int>&f,box* now,int x) {
    if(x == b) return;
    auto found = now->next[f.at(x)];
    if(found) insert(f,found,x + 1);
    else insert(f,now->next[f.at(x)] = new box(),x + 1);
    return;
}
int check(vector<int>&f,box* now,int x) {
    if(x == b) return x;
    if(now->next[f.at(x)]) return check(f,now->next[f.at(x)],x + 1);
    else return x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    while(n--) {
        cin>>a>>b;
        root = box();
        vector<vector<int>>f(a,vector<int>(b));
        for(int j = 0;j<a;j++) {
            for(int &i : f.at(j)) cin>>i,i--;
            vector<int>now(b);
            for(int i = 0;i<b;i++) {
                int tmp = f.at(j).at(i);
                now.at(tmp) = i;
            }
            insert(now,&root,0);
        }
        for(auto &i : f) cout<<check(i,&root,0)<<" ";
        cout<<"\n";
    }
    return 0;
}