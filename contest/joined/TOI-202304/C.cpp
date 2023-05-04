// Author : ysh
// 04/25/2023 Tue  9:38:37.83
#include<bits/stdc++.h>
using namespace std;
struct box{
    vector<box*>next;
    vector<int>count;
    box() {
        next.resize(26);
        count.resize(26);
    }
};
box root;
void insert(box *t,vector<char>&f) {
    if(f.empty()) return;
    int now = f.back() - 'A';
    if(not t->next.at(now)) t->next.at(now) = new box();
    t->count.at(now) = t->count.at(now) + 1;
    f.pop_back();
    insert(t->next.at(now),f);
    return;
}
int check(box *t,vector<char>&f) {
    if(f.empty()) return 0;
    int now = f.back() - 'A';
    f.pop_back();
    return t->count.at(now) + check(t->next.at(now),f);
}
void insert(string a) {
    vector<char>f;
    for(auto &i : a) {
        f.push_back(i);
    }
    reverse(f.begin(),f.end());
    insert(&root,f);
    return;
}
int check(string a) {
    vector<char>f;
    for(auto &i : a) {
        f.push_back(i);
    }
    reverse(f.begin(),f.end());
    return check(&root,f);
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;cin>>n;
    vector<string>f(n);
    for(string &i : f) {
        cin>>i;
        insert(i);
    }
    for(string &i : f) {
        cout<<check(i) - i.size()<<"\n";
    }
    return 0;
}